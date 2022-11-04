#include<iostream>
using namespace std;
struct node
{
	int age;
	node* next;
}Node,*link; //构建了一个头指针link和一个自定义Node;

//写入数据(增)
node*tou_cha(int n)
{
	node* head =(node*)malloc(sizeof(node));
	link = head;
	link->next = NULL;
	
	for (int i = 0; i < n; i++)
	{
		node* p_next =(node*)malloc(sizeof(node));
		if (p_next != NULL)
		{
			p_next->age = i;
			link->next = p_next;
			link = p_next;
			link->next = NULL;
		}	
		
	}
	cout << "链表创建完成" << endl;
	return head;
}

//查看链表
void cha_kan( node* p_head)
{
	node* p;
	p = p_head->next;
	while (p != NULL)
	{
		cout << p->age << " ";
		p = p->next;
	}
	cout << "以上是所以链表里面的元素" << endl;
}

//返回第n个节点，相反，找不到元素，就返回头节点
node* index(node*p_head,int i)
{
	node* p = p_head->next;
	while (p != NULL)
	{
		if (p->age == i)
		{
			return p;
			break;
		}
		p = p->next;//重要的一步
	}
	return p_head;
}

//插入节点，如果找得到链表元素，就将新的元素插入寻找元素后面，相反，找不到元素，就把元素插到最前面
void insert(node* p_head,int i)
{
	node* p = index(p_head, i);
 if (p != NULL)
	{
		node* s = (node*)malloc(sizeof(node));
	
			int nums;
			cout << "输入数字：";
			cin >> nums;
			s->age = nums;
			s->next = p->next;
			p->next = s;
	}
	cout << "插入完成" << endl;
}

//删除指定节点(删)
void Delete(node* p_head, int i)
{
	node* p = index(p_head, i);
	node* s = p_head;

	while (s != NULL)
	{
		if (s->next->age == p->age)
		{
			s->next = p->next;
			break;
		}
		s = s->next;
	}
	cout << "删除完成" << endl;
}

//修改数据
void xiu_gai(node*p_head,int i)
{
	node* p = index(p_head, i);
	int num;
	cout << "输入修改数字";
	cin >> num;
	p->age = num;
}

int main()
{
	node* head = tou_cha(5);
	cha_kan(head);
	cout << "你想在哪个数字后面插入数字" << endl;
	int i;
	cin >> i;
	insert(head,i);
	cha_kan(head);
	cout << "你想删除哪个数字" << endl;
	int n;
	cin >> n;
	Delete(head, n);
	cha_kan(head);

	cout << "你要修改哪个数字" << endl;
	int wei_zhi;
	cin >> wei_zhi;
	xiu_gai(head, wei_zhi);
	cha_kan(head);



	return 0;
}
