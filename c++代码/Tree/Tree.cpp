#include<iostream>
using namespace std;
template<class T>
class Tree;
template<class T>
class Node
{
	friend class Tree<T>;
   public:
	 Node<T>(){ p_Father = NULL, p_lchild = NULL, p_rchild = NULL; }
	 Node<T>(T m_data){ p_Father = NULL, p_lchild = NULL, p_rchild = NULL, data = m_data; }
    ~Node<T>(){}
	T data;
	Node<T>* p_Father;
	Node<T>* p_lchild;
	Node<T>* p_rchild;
	int ltag=0,rtag=0;
};

template<class T>
class Tree
{
 public:
	  Tree();
	/* ~Tree();*/  
	  void resourion(Node<T>*);
	  void createTree(Node<T>* p_head);           //创建二叉树
	  void InThreading(Node<T>* T);   //线索二叉树
	  void Inorder(Node<T>* p, Node<T>* t);        //找当前 前驱节点或后驱节点
	  void InorderTraverse(Node<T>* p);            //遍历二叉树
 private:
	 Node<T>**Array;
	 int size;
	 int capacity;
	 int top;
	 void push(Node<T>*);
	 void judge(Node<T>*);
	 Node<T>* Pop();
	
	
	 Node<T>* pre;
};

template<class T>
Tree<T>::Tree()
{
	this->Array = new Node<T> * [20];
	this->size = 0;
	this->capacity = 20;
	this->top = 0;
	this->pre = NULL;
}

//初始化树

template<class T>
void Tree<T>::createTree(Node<T>* p_head)
{
	T c;
	cin >> c;
	if (c == ' ')
	{
		p_head = NULL;
	}
	else
	{
		p_head = new Node<T>(c);
		createTree(p_head->p_lchild);
		createTree(p_head->p_rchild);
	}
}

//入栈
template<class T>
void Tree<T>::push(Node<T>*node)
{
	if (this->size < this->capacity)
	{
		this->Array[top] = node; //1 2 5
		top++; // 1 2 3
		size++;//3
	}
	else
	{
		cout << "栈满" << endl;
		exit(0);
	}
}

//出栈
template<class T>
Node<T>*Tree<T>::Pop()
{
	if (this->top > 0)
	{
		Node<T>*node;
		node = this->Array[this->top-1];
		top--; //2
		size--;//2
		return node;
	}
	else
	{
		cout << endl;
		cout << "栈为空" << endl;
		exit(0);
	}
}

//非递归二叉树遍历
template<class T>
void Tree<T>::resourion(Node<T>*p_head)

{
	judge(p_head);
	Node<T>* p = p_head;
	while(p&&this->size<this->capacity)
	{
		if (p != NULL)
		{
			this->push(p);
			p = p->p_lchild;
			if (p == NULL)
			{
			flag:
				Node<T>* node = this->Pop(); //
				cout << node->data << " ";
				p = node->p_rchild;
				if (p == NULL)
				{
					goto flag;
				}
			}
		}
	}
}

//给二叉树添加前驱后继标记
template<class T>
void Tree<T>::judge(Node<T>*p_head)
{
	if (p_head == NULL)
	{
		return;
	}
	else
	{
		if (!p_head->p_lchild)
		{
			p_head->ltag = 1;
		   if (!p_head->p_rchild)
		  {
			 p_head->rtag = 1;
		  }
		}
		
		judge(p_head->p_lchild);   //左子树
		judge(p_head->p_rchild);  //右子树
	}
}


//1.前序排列(递归)
template<class T>
void recursion(Node<T>* p_head)
{
	if (p_head == NULL)
	{
		return;
	}
	else
	{
		cout << p_head->data << " ";
		recursion(p_head->p_lchild);   //左子树
		recursion(p_head->p_rchild);  //右子树
	}
}

//中序对二叉树进行线索化
 template<class T>
void Tree<T>::InThreading(Node<T>* T)
 {
	
	if (T)
	{
		InThreading(T->p_lchild);
		if (!T->p_lchild)
		{
			T->ltag = 1;
			T->p_lchild = pre;
		}
		if (!pre->p_rchild)
		{
			pre->rtag = 1;
			pre->p_rchild = T;
		}
	}
	   pre = T;
	   InThreading(T->p_rchild);
}

template<class T>
void Tree<T>::Inorder(Node<T>* p, Node<T>* t)
{
	p = new Node<T>();
	p->ltag = 0;
	p->rtag = 1;
	p->p_rchild = p;
	if (!t)
	{
		p->p_lchild = p;
	}
	else
	{
		p->p_lchild = t;
		this->pre = p;
		this->InThreading(t->p_rchild);
	}
}

template<class T>
void visit(T c)
{

	cout << c << " ";
}

template<class T>
void Tree<T>::InorderTraverse(Node<T>* p)
{
	Node<T>* pp;
	pp = p->p_lchild;
	while (pp != p)
	{
		p = p->p_lchild;
	}
	visit(p->data);
	while (pp->rtag = 1 && pp->p_rchild != p)
	{
		pp = pp->p_rchild;
		visit(pp->data);
	}
}


int main()
{
	Node<int>s1(1);
	Node<int>s2(2);
	Node<int>s3(3);
	Node<int>s4(4);
	Node<int>s5(5);
	Node<int>s6(6);
	Node<int>s7(7);
	Node<int>s8(8);
	Node<int>s9(9);
	
	
	s1.p_lchild = &s2;
	s1.p_rchild = &s3;
	s2.p_Father = &s1;
	s3.p_Father = &s1;

	s2.p_lchild = &s4;
	s4.p_Father = &s2;
	s2.p_lchild = &s5;
	s5.p_Father = &s2;

	s2.p_rchild = &s6;
	s6.p_Father = &s2;

	s4.p_lchild = &s7;
	s7.p_Father = &s4;

	s5.p_rchild = &s8;
	s8.p_Father = &s5;

	s6.p_lchild = &s9;
	s9.p_Father = &s6;

	/*recursion(&s1);*/

//方法一

	Tree<int>t;
	t.resourion(&s1);
	Tree<char>tt;
	Node<int>TT = NULL;
	t.Inorder(&s1, &TT);
	t.InorderTraverse(&s1);

	
//方法2

	Node<char>p;
	Node<char>T = NULL;
	tt.createTree(&T);
	tt.Inorder(&p, &T);
	tt.InorderTraverse(&p);
	
	return 0;
}