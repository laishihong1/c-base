#include<iostream>
using namespace std;

template<class T1,class T2>
class link;

template<class T1, class T2>
class node
{
	friend class link<T1,T2>;
 public:
	 node<T1, T2>(node<T1, T2>* p = NULL) { next = p; }  //用于创建头节点
	 node<T1, T2>(const T1& i, const T2& j, node<T1, T2>* p = NULL) : a(i), b(j),next(p){}//用于创建节点
 private:
	 T1 a;
	 T2 b;
	 node<T1,T2>* next;
};

template<class T1, class T2>
class link
{
public:
	link<T1, T2>() { p_head = new node<T1, T2>(); size = 0; }
	~link<T1, T2>();
	 node<T1, T2>* adds(int); //增加
	void insert(int i, const T1& name, const T2& age); //input
	void Delete(int);//删
	node<T1, T2>* index(node<T1, T2>* p_head,int i);
	void xiu_gai(int);
	void getdata(int);//查
	void ni_zhi();//逆置单链表
	void Delete_max();//删除最大数
	void pai_xu();//链表排序
	int num_index(int);
	 void disp();
	int Size()const;
private:
	 int size;
	 node<T1, T2>* p_head; //头指针
};

//初始化
template<class T1, class T2>
link<T1, T2>::~link<T1, T2>()
{
	node<T1, T2>* p;
	node<T1, T2>* q;

	p = p_head;
	while (p != NULL)
	{
		q = p->next;
		delete p;
		p = q;
	}
} 

//链表数据添加
template<class T1, class T2>
node<T1, T2>* link<T1, T2>::adds(int length) //增加
{
	node<T1, T2>* pre;
	pre = p_head;
	while(size<length)
	{
		string name;
		cout << "输入姓名：";
		cin >> name;
		int ages;
		cout << "输入年龄：";
		cin >> ages;
		node<T1, T2>* pp = new node<T1, T2>(name, ages);
		pre->next = pp;
		pre = pp;
		size++;
	}
	return p_head;
}

//插入数据
template<class T1, class T2>
void link<T1, T2>::insert(int i,const T1&name,const T2&age)//插入
{
	if (i<-1 || i>size - 1)
	{
		cout << "你输入的参数不正确" << endl;
		exit(0);
	}

	node<T1, T2>* p = index(p_head, i);
	if (p != NULL)
	{
		node<T1, T2>* e = new node<T1, T2>(name,age);
		e->next = p->next;
		p->next = e;
		size++;
	}
	cout << "插入数据进行排序后为：";
	pai_xu();
}

//删除数据
template<class T1, class T2>
void link<T1, T2>::Delete(int i)//删
{
	if (i<-1 || i>size)
	{
		cout << "参数错误" << endl;
		exit(0);
	}

	node<T1, T2>* p =index(p_head,i),*pp;
	pp = p_head;
	while (pp != NULL)
	{
		if (pp->next->b == p->b)
		{
			pp->next = p->next;
			delete p;
			break;
		}
		pp = pp->next;
	}
	size--;
}

//返回指定节点
template<class T1, class T2>
node<T1, T2>* link<T1, T2>::index(node<T1, T2>* p_head,int i)
{
	if (i<-1 || i>size)
	{
		cout << "你输入的参数不正确" << endl;
		exit(0);
	}
	if (i == -1)
	{
		return p_head;
	}

	node<T1, T2>* p;
	p = p_head;
	int j = 0;
	while (p != NULL&&j<i)
	{
		p = p->next;
		j++;
	}
	return p;
}

//修改指定下标的内容
template<class T1, class T2>
void link<T1,T2>::xiu_gai(int i)
{
	node<T1, T2>* p = index(p_head, i);
	int choice;
	cout << "你想修改什么？1.姓名，2.年龄";
	cin >> choice;
	if (choice == 1)
	{
		string names;
		cout << "输入新的名字";
		cin >> names;
		p->a = names;
		cout << "修改完成" << endl;;
	}
	else if (choice == 2)
	{
		int Age;
		cout << "输入年龄" << endl;
		cin >> Age;
		p->b = Age;
		cout << "修改完成" << endl;
	}
}


//取得数据
template<class T1, class T2>
void link<T1, T2>::getdata(int i)//查
{
	if (i<-1 || i>size)
	{
		cout << "下标有错误" << endl;
		exit(0);
	}
	node<T1, T2>* p = index(p_head, i);
	if (p != NULL)
	{
		cout << "姓名：" << p->a << " " << "年龄：" << p->b << endl;
	}	
}

template<class T1,class T2>
void link<T1, T2>::ni_zhi()//逆置单链表
{
	node<T1, T2>* p = p_head;
	int length = 0;
	while (length != this->size)
	{
		node<T1, T2>* e = index(p_head, size);
		e->next = p->next;
		p->next = e;
		p = e;
		length++;
	}
	p->next = NULL;
}


//删除最大数
template<class T1,class T2>
void link<T1, T2>::Delete_max()//删除最大数
{
	node<T1, T2>* p = p_head->next;
		int num=0;
	   num = p->b;
	   int i = 0;
	while (p != NULL)
	{
		if (num <= p->b)
		{
			num = p->b;
		}
		p = p->next;
	}
	i=num_index(num);
	Delete(i);
}

//链表排序
template<class T1,class T2>
void link<T1, T2>::pai_xu()//链表排序
{
	if (p_head->next == NULL)
	{
		exit(0);
	}
	node<T1, T2>* head, * pre, * cur, * n_next, * end, * temp;
	head = p_head;
	end = NULL;
	while (head->next != end)
	{
		for (pre = head, cur = pre->next, n_next = cur->next; n_next != end; pre = pre->next, cur = cur->next, n_next = n_next->next)
		{
			if (cur->b > n_next->b)
			{
				cur->next = n_next->next;
				pre->next = n_next;
				n_next->next = cur;
				temp = n_next;
				cur = temp;
			}
		}
		end = cur;
	}
	disp();
}


//返回下标
template<class T1, class T2>
int link<T1, T2>::num_index(int i)
{
	node<T1, T2>* p = p_head->next;
	int length = 1;
	while (p != NULL)
	{
		if (i == p->b)
		{
			return length;
			break;
		}
		length++;
		p = p->next;
	}
	return -1;
}

//返回链表长度
template<class T1, class T2>
int link<T1, T2>::Size()const
{
	return size;
}

//打印
template<class T1,class T2>
void link<T1,T2>::disp()
{
	node<T1, T2>* p = adds(Size())->next;
	
	while (p != NULL)
	{
		cout<<"姓名：" << p->a << " " <<"年龄："<< p->b << " " << endl;
		p = p->next;
	}
}

//主函数
int main()
{
	link<string,int>l;
	l.adds(2); //添加两个数据
	l.disp();
	cout << endl;
	l.insert(1, "ls", 19); //插入数据
	cout << endl;
	l.ni_zhi();          //链表逆置
	cout << endl;
	l.Delete(1);      //删除下标为1的数元素
	l.disp();
	cout << endl;
	l.getdata(1);      //取得下标为1的元素
	cout << endl;
	l.xiu_gai(1);      //修改下标为1的元素
	l.disp();
	cout << endl;
	l.Delete_max();      //删除最大值
	l.disp();
	return 0;
}