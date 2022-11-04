#include<iostream>
using namespace std;
const int SIZE = 10;
template<class T>
class Loop_Queue
{
 public:
	  Loop_Queue();
	 ~Loop_Queue();
	 void pop_(T num);
	  void push();
	  int Size();
	  bool isEmpty();
	  bool isFull_Back();
 private:
	 T* array;
	 int size;
	 int capacity;
	 int top;
	 int end;
};


template<class T>
Loop_Queue<T>::Loop_Queue()
{
	capacity = SIZE;
	this->array = new T[capacity];
	top = end = 0;
	size = 0;
}

template<class T>
Loop_Queue<T>::~Loop_Queue()
{
	if (this->array != NULL)
	{
		delete[]this->array;
		this->array = NULL;
	}
}

template<class T>
void Loop_Queue<T>::pop_(T num)
{
	if (size != capacity)
	{
		this->array[end] = num;
		size++;
		end++;
	}
}

template<class T>
void Loop_Queue<T>::push()
{
	cout << this->array[top] << " ";
	top++;
}

template<class T>
int Loop_Queue<T>::Size()
{
	return size;
}

template<class T>
bool  Loop_Queue<T>::isEmpty()
{
	if (top == end)
	{
		return true;
	}
	return false;
}

template<class T>
bool Loop_Queue<T>::isFull_Back()
{
	if (end == capacity)
	{
		return true;
	}
	return false;
}


int main()
{
	Loop_Queue<string>queue;
	queue.pop_("one");
	queue.pop_("two");
	queue.pop_("three");
	queue.pop_("four");
	queue.pop_("five");

	for (int i = 0; i < queue.Size(); i++)
	{
		queue.push();
	}

	return 0;
}