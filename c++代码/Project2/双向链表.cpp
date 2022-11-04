#include<iostream>
using namespace std;
typedef int DataType;
template<class T>
class link;

template<class T>
class node
{
	friend class link<T>;
 public:
	 node(node<T>* M_pre = NULL,node<T>*M_next=NULL):pre(M_pre),next(M_next){} //头节点
	 node(T num, node<T>* M_pre = NULL, node<T>* M_next = NULL) :pre(M_pre), next(M_next) { a = num; } //节点
 private:
	 T a;
	 node<T>* pre;
	 node<T>* next;
};

template<class T>
class link
{
 public:
	 link();
	 ~link();
	 void add(DataType i); //添加
	 void insert(DataType i); //插入
	 void Delete(DataType i); //删除
	 void xiu_gai(DataType i); //修改
	 void take_though(); //查找
	 node<T>* index(node<T>* p_head, DataType i); //返回下标
	 void disp();
 private:
	 DataType size;
	 node<T>* p_head;  //头指针
};

template<class T>
link<T>::link()
{
	p_head = new node<T>();
	p_head->pre = p_head;
	p_head->next = p_head;
	size = 0;
}

template<class T>
link<T>::~link()
{

}


//增加

template<class T>
void link<T>::add(DataType i) //增
{
	node<T>* p = p_head;
	while (size < i)
	{
		int num;
		cout << "输入数字：";
		cin >> num;
		node<T>* p_next = new node<T>(num);

		p->next = p_next;
		p_next->pre = p;
		p = p_next;

		size++;
		if (size == i)
		{
			p->next = p_head;
			p_head->pre = p;
		}
	}	
}

//插入

template<class T>
void link<T>::insert(DataType i)
{
	node<T>* p = index(p_head, i);
	int num;
	cout << "请输入数字：";
	cin >> num;
	node<T>* e = new node<T>(num);

	p->next->pre = e;
	e->next = p->next;

	p->next = e;
	e->pre = p;
	 

	cout << "数据插入完成" << endl;
}

//删除

template<class T>
void link<T>::Delete(DataType i) //删
{
	node<T>* e = index(p_head, i);
	e->pre->next = e->next;
	e->next->pre = e->pre;
	delete e;
	cout << "删除完成" << endl;
}

template<class T>
void link<T>::xiu_gai(DataType i) //修改
{
	node<T>* p = index(p_head, i);
	int num;
	cout << "请重新输入数字：";
	cin >> num;
	p->a = num;
	cout << "修改完成" << endl;
}

template<class T>
void link<T>::take_though() //查找
{
	int num;
	cout << "请输入你要查找的数字：";
	cin >> num;
	node<T>* p = p_head->next;
	node<T>* pp = p_head->pre;
	while (p!=p_head||pp!=p_head)
	{
		if (p->a == num||pp->a==num)
		{
			cout << "已查到,你要的数字" << p->a << "在链表当中" << endl;
			break;
		}
		p = p->next;
		pp = pp->pre;
		if (pp == p)
		{
			cout << "链表没有当前元素" << endl;
			break;
		}
	}
}



//返回下标
template<class T>
node<T> * link<T>::index(node<T>* p_head, DataType i) //返回下标
{
	if (i<-1 || i>size - 1)
	{
		cout << "下标参数越出" << endl;
		exit(0);
	}
	if (i == -1)
	{
		return p_head;
	}

	node<T>* p = p_head->next;
	DataType j = 0;
	while (p != p_head && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}


//打印数据

template< class T>
void link<T>::disp()
{
	node<T>* p = p_head->next;
	cout << "数字有：";
	while (p != p_head)
	{
		cout << p->a << " ";
		p = p->next;
	}
}


int main()
{

	link<int>l;

	l.add(2);
	l.disp();
	cout << endl;
	l.insert(0);
	l.disp();
	cout << endl;
	l.Delete(1);
	l.disp();
	cout << endl;
	l.xiu_gai(1);
	l.disp();
	l.take_though();
	return 0;
}