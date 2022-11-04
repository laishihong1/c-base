#include <stdio.h>
#include <stdlib.h>
#define maxSize 100

//树的定义
typedef struct CSNode
{
	char data;
	struct CSNode* firstchild, * nextsibling;
}CSNode, * CSTree;

//二叉树的定义
typedef struct BTNode
{
	char data;
	struct BTNode* lchild;
	struct BTNode* rchild;
}BTNode;

//新森林定义
typedef struct
{
	CSTree ct[maxSize];
	int num;
}Forest;

//旧森林定义
/*typedef struct
{
	CSTree *ct;
	int num;
}Forest;*/

//存储路径定义
typedef struct
{
	char path[100];
}Str;

//文件指针
FILE* fp;

//创建一棵树
CSTree CreateCSTree()
{
	char ch;
	fscanf(fp, "%c", &ch);
	CSTree CT = NULL;
	if (ch != '0')
	{
		CT = (CSNode*)malloc(sizeof(CSNode));
		CT->data = ch;
		CT->firstchild = CreateCSTree();
		CT->nextsibling = CreateCSTree();
	}
	return CT;
}

//树转换成二叉树
BTNode* ExchangeToBTree(CSTree ct)
{
	if (ct == NULL)
		return NULL;
	else
	{
		BTNode* bt = (BTNode*)malloc(sizeof(BTNode));
		bt->data = ct->data;
		bt->lchild = ExchangeToBTree(ct->firstchild);
		bt->rchild = ExchangeToBTree(ct->nextsibling);
		return bt;
	}
}

//二叉树转换成树
CSTree ExchangeToCSTree(BTNode* bt)
{
	if (bt == NULL)
		return NULL;
	else
	{
		CSTree ct = (CSNode*)malloc(sizeof(CSNode));
		ct->data = bt->data;
		ct->firstchild = ExchangeToCSTree(bt->lchild);
		ct->nextsibling = ExchangeToCSTree(bt->rchild);
		return ct;
	}
}

//森林转二叉树
BTNode* ForestToBTree(CSTree F[], int low, int high)
{
	//low为当前指向的树，high为第n棵树的下标n-1
	if (low > high)
		return NULL;
	else
	{
		BTNode* root = ExchangeToBTree(F[low]);//二叉树的根即为第一棵树的根，同时二叉树的左孩子是第一棵树根节点的子树森林转化成的二叉树
		root->rchild = ForestToBTree(F, low + 1, high);//二叉树的右子树是森林其他树转换成的二叉树
		return root;
	}
}

//二叉树转森林
Forest* BTreeToForest(BTNode* root)
{
	BTNode* p = root;

	//森林初始化
	Forest* F = (Forest*)malloc(sizeof(Forest));
	BTNode* q = NULL;

	int i = 0;//统计树的个数

	//将二叉树转化为森林，核心代码
	while (p != NULL)
	{
		q = p->rchild;//先用q指向下一棵树的根节点
		p->rchild = NULL;//将当前有右孩子的二叉树的右孩子链接断开
		F->ct[i++] = ExchangeToCSTree(p);//将二叉树转化为树
		p = q;//将p指向下一棵树
	}

	F->num = i;
	return F;
}
/*void BTreeToForest(Forest* F, BTNode* root)
{
	BTNode* p = root;
	int n = 0;
	//计算二叉树内包含了多少棵树
	while (p)
	{
		++n;
		p = p->rchild;
	}
	//如果是一个空的二叉树，则森林也为空
	if (n == 0)
	{
		F->ct = NULL;
		F->num = 0;
	}
	else
	{
		//森林初始化，创建一个包含n棵树的数组，数组元素为CSNode*类型，即CSTree类型
		F->ct = (CSTree*)malloc(sizeof(CSTree)*n);
		BTNode* q = NULL;
		int i = 0;
		p = root;
		//将二叉树转化为森林，核心代码
		while (p != NULL)
		{
			q = p->rchild;//先用q指向下一棵树的根节点
			p->rchild = NULL;//将当前有右孩子的二叉树的右孩子链接断开
			F->ct[i++] = ExchangeToCSTree(p);//将二叉树转化为树
			p = q;//将p指向下一棵树
		}
		F->num = n;
	}
}*/


//二叉树先序遍历
void preorder(BTNode* bt)
{
	if (bt != NULL)
	{
		printf("%c", bt->data);
		preorder(bt->lchild);
		preorder(bt->rchild);
	}
}

//二叉树中序遍历
void inorder(BTNode* bt)
{
	if (bt != NULL)
	{
		inorder(bt->lchild);
		printf("%c", bt->data);
		inorder(bt->rchild);
	}
}

//树的先序遍历
void preorder_cstree(CSTree ct)
{
	if (ct != NULL)
	{
		printf("%c", ct->data);
		preorder_cstree(ct->firstchild);
		preorder_cstree(ct->nextsibling);
	}
}

//树的后序遍历=二叉树的中序遍历
void inorder_cstree(CSTree ct)
{
	if (ct != NULL)
	{
		inorder_cstree(ct->firstchild);
		printf("%c", ct->data);
		inorder_cstree(ct->nextsibling);
	}
}

//森林先序遍历
void preorder_forest(Forest* f)
{
	int i;
	for (i = 0; i < f->num; ++i)
		preorder_cstree(f->ct[i]);
}

//森林后序遍历
void inorder_forest(Forest* f)
{
	int i;
	for (i = 0; i < f->num; ++i)
		inorder_cstree(f->ct[i]);
}

int main()
{
	//用来测试树的创建、森林转二叉树、二叉树转森林

	//创建一个森林
	CSTree F[3];
	Str ps[3] = { "C:\\CodeBlocksProject\\cstree1.txt" ,"C:\\CodeBlocksProject\\cstree2.txt" ,"C:\\CodeBlocksProject\\cstree3.txt" };
	int length = 3;
	for (int i = 0; i < length; i++)
	{
		fp = fopen(ps[i].path, "r");
		F[i] = CreateCSTree();
		fclose(fp);
	}

	//森林转二叉树
	BTNode* bt = ForestToBTree(F, 0, length - 1);

	//二叉树转森林
	Forest* F2;
	F2 = BTreeToForest(bt);
	inorder_forest(F2);

	//对森林的第三棵树进行树的前序遍历，测试代码正确性
	//preorder_cstree(F2->ct[0]);


	//下面注释掉的内容是对创建树、树转二叉树、二叉树转树的代码测试

	//fp = fopen("C:\\CodeBlocksProject\\cstree.txt", "r");
	//CSTree ct = CreateCSTree();
	//preorder_cstree(ct);
	//BTNode* bt = ExchangeToBTree(ct);
	//CSTree ct2 = ExchangeToCSTree(bt);
	//preorder_cstree(ct2);
	//preorder(bt);
	//inorder(bt);


	system("pause");

	return 0;
}