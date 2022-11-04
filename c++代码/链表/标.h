#include<iostream>
using namespace std;
template<class T>
class Links;

//类模板 
template<class T>
class Link_list
{
	friend class Links<T>;

public:
	Link_list(Link_list<T>* p_next = NULL)
	{
		next = p_next;
	}

	Link_list(const T& num, Link_list<T>* p_next = NULL)//有参构造函数 
	{
		data = num;
		next = p_next;
	}

private:
	Link_list<T>* next;
	T data;
};

template<class T>
class Links
{
public:
	Links();
	~Links();

	int Size()const;
	void Insert(const T& num, int i); //（插入数据，位数 ）
	T Delete(int i);
	T getData(int i);
private:
	Link_list<T>* head;//头结点 
	int sizes;     //size用于统计节点个数，以便于后面进行增删改查等功能；
	Link_list<T>* index(int i);
};

template<class T>
Links<T>::Links()
{
	head = new Link_list<T>;
	sizes = 0;
}

template<class T>
Links<T>::~Links()
{
	Link_list<T>* p;
	Link_list<T>* q;
	p = head;
	while (p != NULL)
	{
		q = p;
		p = p->next;
		delete p;
	}
	sizes = 0;
	head = NULL;
}

template<class T>
Link_list<T>* Links<T>::index(int i)
{
	if (i<-1 || i>sizes - 1)
	{
		cout << "参数越出" << endl;
		exit(0);
	}
	if (i == 0)
	{
		return head;
	}

	Link_list<T>* p = head->next;

	int j = 0;

	while (p != NULL && j < i)
	{
		p = p->next;
		j++;
	}
	return p;
}

template<class T>
int Links<T>::Size()const
{
	return sizes;
}

template<class T>
void Links<T>::Insert(const T& num, int i) //（插入数据，位数 ）
{
	if (i<0 || i>sizes)
	{
		cout << "输入值无效" << endl;
		exit(0);
	}
	Link_list<T>* p = index(i - 1);
	Link_list<T>* q = new Link_list<T>(num, p->next);
	p->next = q;
	sizes++;
}

template<class T>
T Links<T>::Delete(int i)
{
	if (sizes == 0)
	{
		cout << "链表为空" << endl;
		exit(0);
	}
	if (i<0 || i>sizes - 1)
	{
		cout << "参数输入错误" << endl;
		exit(0);
	}
	Link_list<T>* s, * p = index(i - 1);
	s = p->next;
	p->next = p->next->next;
	T x = s->data;
	delete s;
	sizes--;
	return x;

}

template<class T>
T Links<T>::getData(int i)
{
	if (i<0 || i>sizes)
	{
		cout << "输入值无效" << endl;
		exit(0);
	}
	Link_list<T>* p = index(i);
	return p->data;
}

