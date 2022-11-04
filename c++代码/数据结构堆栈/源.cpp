#include<iostream>
using namespace std;
template<class T>
class Strck;
template<class T>
class Node
{
	friend class Strck<T>;
public:
	Node(Node<T>* p = NULL){ p_next = p; }
    Node(const T &m_num,Node<T>* p = NULL):p_next(p),num(m_num){}
   ~Node(){}
private:
	T num;
	Node<T> *p_next;
};

template<class T>
class Strck
{
public:
	Strck(int);
   //~Strck();
	void Add(int num);        //增加
	void Disp();      //打印栈
	void Size();       //返回栈的大小
private:
	int size;    //数量
	int capacity;//容量

	Node<T>*strck_Top;  //创建栈顶
	bool M_Empty();
	bool M_PackFull();
	Node<T>* Push_Back(); //出栈
	void* Pop_Back(int num);  //压栈
};
template<class T>
Strck<T>::Strck(int m_capacity)
{
	this->capacity = m_capacity;
	this->size = 0;
	this->strck_Top = new Node<T>();
}

template<class T>
bool Strck<T>::M_Empty()
{
	if (this->size < this->capacity)
	{
		return true;
	}
	cout << "栈为空" << endl;
	return false;
}

template<class T>
bool Strck<T>::M_PackFull()
{
	if (this->size == this->capacity)
	{
		cout << "栈满" << endl;
		return true;
	}
	return false;
}

template<class T>
void Strck<T>::Add(int num)
{
	if (M_Empty()||(!M_PackFull()))
	{
		this->Pop_Back(num);
	}
	else
	{
		cout << "栈满" << endl;
		exit(0);
	}
}

template<class T>
void* Strck<T>::Pop_Back(int num)
{
	if (this->M_PackFull())
	{
		exit(0);
	}
	Node<T>* New_Space = new Node<T>(num);
	New_Space->p_next = this->strck_Top;
	this->strck_Top = New_Space;
	this->size++;
 }

template<class T>
Node<T>* Strck<T>::Push_Back()
//出栈
{
	if (this->strck_Top == NULL || this->strck_Top->num == 0)
	{
		exit(0);
	}
	
		Node<T>* e = new Node<T>();
		*e = this->strck_Top->num;
		Node<T>* p = this->strck_Top->p_next;
		delete this->strck_Top;
		this->strck_Top = p;
		this->size--;
		return e;
	
}

template<class T>
void Strck<T>::Disp()     //打印栈
{
	while (true)
	{
		if (this->M_Empty())
		{
			Node<T>* p = Push_Back();
			cout << p->num << " ";
		}
		else
		{
			cout << "栈为空" << endl;
			break;
		}

	}
	
}

template<class T>
void Strck<T>::Size()        //返回栈的大小
{
	return this->size;
}

int main()
{
	Strck<int>s(10);
	s.Add(1);
	s.Add(2);
	s.Add(3);
	s.Disp();
	/*s.Disp();
	s.Disp();*/
	return 0;
}