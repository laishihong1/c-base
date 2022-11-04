#include<iostream>
using namespace std;
const int Size = 10;
class List_Array;
class Node
{
	friend class List_Array;
public:
	 Node() { num = 0; }
	~Node() {}
private:
	int num;
};

class List_Array
{
public:
	List_Array();
	~List_Array(){}
	void add(int);
	void disp();
private:
	void push_back(const int&);
	int pop_back();
	Node* Array;
	int top;
	int size;
	int capacity;
	bool M_empty();
	bool M_backfull();
};

List_Array::List_Array()
{
	this->Array = new Node[Size];
	this->top = -1;
	capacity = Size;
	this->size = 0;
}

void List_Array::push_back(const int&nums)
{
	if (this->M_empty())
	{
		this->Array[this->size].num = nums;
		this->top++;
		this->size++;
	}
	if (this->M_backfull())
	{
		cout << "Õ»Âú" << endl;
		exit(0);
	}
}

int List_Array::pop_back()
{
	if (this->M_empty())
	{
		int number = this->Array[this->top].num;
		this->top--;
		return number;
	}
	else {
		cout << "Õ»Îª¿Õ" << endl;
		exit(0);
	}
}

bool List_Array::M_empty()
{
	if (this->size == 0||this->size!=this->capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool List_Array::M_backfull()
{
	if (this->size >= this->capacity)
	{
		return true;
	}
	else
	{
		return false;
	}
}


void List_Array::add(int num)
{
	this->push_back(num);
}

void List_Array::disp()
{
	int num=this->pop_back();
	cout << num << " ";
}

int main()
{
	List_Array l;
	l.add(1);
	l.add(2);
	l.add(3);
	l.disp();
	l.disp();
	l.disp();
	return 0;
}