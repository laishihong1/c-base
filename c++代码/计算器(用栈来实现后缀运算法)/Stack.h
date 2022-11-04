#pragma once
#include<iostream>
using namespace std;
template<class T>
class Stack;

template<class T>
class node
{
	friend class Stack<T>;
public:
	node<T>() { next = NULL; data = '\0'; }
	node<T>(T m_data) { next = NULL; data = m_data; }
	~node<T>() {}
private:
	node<T>* next;
	T data;
};

template<class T>
class Stack
{
public:
	Stack();
	/*~Stack();*/
	void pin_zhuang(const T m_array[], int size);
	void disp();
	
private:
	node<T>* top;
	int array_size;
	int capacity;
	char* array;
	void Push(T data);
	void calcolator();
	int Size();
	T Pop();
	int levels(char c);
	bool is_Empty();
	bool is_No_maKeFull();
	bool is_yun_suan_fu(char c);
	bool is_exist(char c);
};

template<class T>
Stack<T>::Stack()
{
	this->top = new node<T>();
	this->capacity = 20;
	this->array = new char[30];
	this->array_size = 0;
}

//template<class T>
//Stack<T>::~Stack()
//{
//	node<T>* p = this->top;
//	node<T>* p_next = this->top->next;
//	if (p != NULL)
//	{
//		delete p;
//		p = p_next;
//		p_next = p_next->next;
//	}
//	delete[]this->array;
//}

template<class T>
void Stack<T>::pin_zhuang(const T m_array[], int size)
{
	int length = 0;

	for (int i = 0; i < size; i++)
	{
		if ((m_array[i]) == ')')
		{
			while (this->top->data != '(')
			{
				this->array[length] = this->Pop();
				length++;
			}
			node<T>* e = new node<T>();
			e->data = this->Pop();
			delete e;
			continue;
		}
		int xiaBiao = i;
		if (isdigit(m_array[i]))
		{
			/*for (int j = xiaBiao; j < size; j++)
			{
				if (isdigit(m_array[j]))
				{
					cin.putback(m_array[i]);
				}
				else {
					break;
				}
			}
			int shu_zi;
			cin >> shu_zi;*/
			this->array[length] = m_array[i];
			length++;
			continue;
		}

		else if (this->is_yun_suan_fu(m_array[i]))
		{

			if (this->is_Empty() || m_array[i] == '(')
			{
				this->Push(m_array[i]);
				continue;
			}

			else if (this->levels(m_array[i]) > this->levels(this->top->data))
			{
				this->Push(m_array[i]);
				continue;
			}

			else if (this->is_exist(m_array[i]))
			{
				while (this->top->data != '\0')
				{
					this->array[length] = this->Pop();
					length++;
				}
				this->Push(m_array[i]);
				continue;
			}
		}


		else if (this->levels(m_array[i]) <= this->levels(this->top->data))
		{
			this->array[length] = this->Pop();
			this->Push(m_array[i]);
			length++;
			continue;
		}

	}
	while (this->top->next != NULL)
	{
		this->array[length] = this->Pop();
		length++;
	}
	this->array_size = length;
	this->calcolator();
}

template<class T>
void Stack<T>::Push(T data)
{
	if (this->is_No_maKeFull())
	{
		node<T>* p = this->top;
		node<T>* pre = new node<T>(data);
		pre->next = p;
		p = pre;
		this->top = p;
	}
	else {
		cout << "栈已经装满" << endl;
		exit(0);
	}
}

template<class T>
T Stack<T>::Pop()
{
	node<T>* p_next = this->top->next;
	if (this->Size() == 0)
	{
		cout << "栈内为空" << endl;
		exit(0);
	}
	else
	{
		if (this->top != NULL)
		{
			T e;
			e = this->top->data;
			delete this->top;
			this->top = p_next;
			return e;
		}
		else {
			cout << "栈为空" << endl;
			exit(0);
		}
	}
}

template<class T>
bool Stack<T>::is_Empty()
{
	if (this->Size() == 0)
	{
		return true;
	}
	return false;
}

template<class T>
bool Stack<T>::is_No_maKeFull()
{
	if (this->is_Empty() || this->Size() < this->capacity)
	{
		return true;
	}
	return false;
}

template<class T>
int Stack<T>::Size()
{
	int size = 0;
	node<T>* p = this->top;
	while (p != NULL)
	{
		p = p->next;
		size++;
	}
	return size;
}

template<class T>
int Stack<T>::levels(char c)
{
	int level = 0;
	switch (c)
	{
	case '(':
	case ')':
		level = 1;
		break;
	case '+':
	case '-':
		level = 2;
		break;
	case '*':
	case '/':
		level = 3;
	default:
		break;
	}
	return level;
}

template<class T>
bool Stack<T>::is_yun_suan_fu(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
	{
		return true;
	}
	else {
		return false;
	}
}

template<class T>
void Stack<T>::disp()
{
	node<T>* p = this->top;
	cout << "计算结果：";
	if (p != NULL) 
	{
		cout << (p->data-'0') << endl;
		p = p->next;
	}
}

template<class T>
bool Stack<T>::is_exist(char c)
{
	node<T>* p = this->top;
	while (p != NULL)
	{
		if (c == p->data)
		{
			return true;
			break;
		}
		p = p->next;
	}

	return false;

}

template<class T>
void  Stack<T>::calcolator()
{
	int total=0;
	int num1 = 0;
	int num2 = 0;
	
	for (int i = 0; i < this->array_size; i++)
	{
		char totals = '0';
		if (isdigit(this->array[i]))
		{/*
			int size = i;
			int nums;
			while (true)
			{
				if (isdigit(this->array[size]))
				{
					cin.putback(this->array[size]);
					size++;
				}
				else {
					break;
				}
			}
			cin >> nums;
			this->Push(nums);*/
			this->Push(this->array[i]);
		}

		else if (this->is_yun_suan_fu(this->array[i]))
		{
			if (this->Size() >= 2)
			{
				num1 = (this->Pop() - '0');
				num2 = (this->Pop() - '0');
				switch (this->array[i])
				{
				case '+':
					total = num2 + num1;
					totals += total;
					break;
				case '-':
					total = num2 - num1;
					totals += total;
					break;
				case'*':
					total = num2 * num1;
					totals += total;
					break;
				case'/':
					total = num2 / num1;
					totals += total;
					break;
				default:
					break;
				}
				this->Push(totals);
			}
		}
	}
}