#include<iostream>
using namespace std;
template<class T>
class Queue;

template<class T>
class Node
{
	friend class Queue<T>;
 public:
	 Node() { next = NULL; }
	 Node(T n) { next = NULL; num = n; }
 private:
	 T num;
	 Node<T>* next;
};

template<class T>
class Queue
{
 public:
	  Queue();
	// ~Queue();
	 bool is_Empty();
	 bool is_BackFull();
	 void push(T num);
	 Node<T>* pop();
	 void disp();
 private:
	 Node<T>* top;
	 Node<T>* end;
	 int size;
	 int capacity;
	 int Size();
};

template<class T>
Queue<T>::Queue()
{
	 Node<T>* head = new Node<T>();
	 this->end = head;
	 this->top = head;
	size = 0;
	capacity = 10;
}

template<class T>
void Queue<T>::push(T num)//入队
{
	if (!this->is_BackFull())
	{
		Node<T>* e = new Node<T>(num);
		this->end->next = e;
		end = e;
		size++;
	}
	else
	{
		cout << "队列已满" << endl;
		exit(0);
	}
}

template<class T>
Node<T>* Queue<T>::pop() //出队
{
	if (!this->is_Empty())
	{
		Node<T>* e = this->top->next;
		Node<T>* p = new Node<T>();
		p->num = e->num;
		delete this->top;
		this->top = e;
		this->size--;
		return p;		
	}
	else
	{
		cout << "队列为空" << endl;
	}
}

template<class T>
void Queue<T>::disp()
{
	Node<T>* p = this->pop();
	if (p != this->end)
	{
		cout << p->num << " ";
	}

}

template<class T>
int Queue<T>::Size()
{
	return size;
}

template<class T> 
bool Queue<T>::is_Empty() //为空
{
	if (this->size == 0)
	{
		return true;
	}
	return false;
}

template<class T>
bool Queue<T>::is_BackFull()//为满
{
	if (this->size >= this->capacity)
	{
		return true;
	}
	return false;
}


int main()
{
	Queue<string>s;
	s.disp();
	s.push("one");
	s.push("two");
	s.disp();
	s.push("three");
	s.disp();
	s.disp();
	s.disp();
	return 0;
}