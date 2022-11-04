#include<iostream>
using namespace std;
const int SIZE = 10;
//#define SIZE 10

class Queue;
class Node
{
	friend class Queue;
public:
	Node() {
		this->p_next = NULL;
		this->p_pre = NULL;
		this->data = '\0';
	}
	Node(char m_data) {
		this->p_next = NULL;
		this->data = m_data;
		this->p_pre = NULL;
	}
	
	Node* p_next;
	char data;
	Node* p_pre;
private:
};

class Queue
{
public:
	Queue();
	Node* add(char*, int);

private:
	Node* p_head;
	int size;
};

Queue::Queue()
{
	this->p_head = new Node();
	this->size = 0;
}

Node* Queue::add(char* data, int size)
{
	Node* p = this->p_head;
	for (int i = 0; i < size; i++)
	{
		Node* newNode = new Node(data[i]);
		newNode->p_next = p;
		p->p_pre = newNode;
		p = newNode;
		if (i+1 > size-1)
		{
			newNode->p_pre = p_head;
			p_head->p_next = newNode;
			break;
		}
	}
	p_head = p;
	return p_head;
}

int isHuiWen(Node* list, int size)
{
	Node* p = list;
	Node* p1 = list->p_pre;
		int i = 0;
		while (i<size)
		{
			if (i == size - 1)
			{
				return 1;
			}
			p = p->p_next;
			p1 = p1->p_pre;
			i++;
	}
	return 0;
}

int main()
{
	Queue q;
	char Array[SIZE];
	cin >> Array;
	int size = strlen(Array);
	Node* s = q.add(Array, size);
	int judge = isHuiWen(s, size);
	if (judge > 0)
	{
		cout << "这是一个回文数" << endl;
	}
	else
	{
		cout << "这不是一个回文数" << endl;
	}
	return 0;
}