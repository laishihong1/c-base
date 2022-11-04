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
	 node(node<T>* M_pre = NULL,node<T>*M_next=NULL):pre(M_pre),next(M_next){} //ͷ�ڵ�
	 node(T num, node<T>* M_pre = NULL, node<T>* M_next = NULL) :pre(M_pre), next(M_next) { a = num; } //�ڵ�
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
	 void add(DataType i); //���
	 void insert(DataType i); //����
	 void Delete(DataType i); //ɾ��
	 void xiu_gai(DataType i); //�޸�
	 void take_though(); //����
	 node<T>* index(node<T>* p_head, DataType i); //�����±�
	 void disp();
 private:
	 DataType size;
	 node<T>* p_head;  //ͷָ��
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


//����

template<class T>
void link<T>::add(DataType i) //��
{
	node<T>* p = p_head;
	while (size < i)
	{
		int num;
		cout << "�������֣�";
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

//����

template<class T>
void link<T>::insert(DataType i)
{
	node<T>* p = index(p_head, i);
	int num;
	cout << "���������֣�";
	cin >> num;
	node<T>* e = new node<T>(num);

	p->next->pre = e;
	e->next = p->next;

	p->next = e;
	e->pre = p;
	 

	cout << "���ݲ������" << endl;
}

//ɾ��

template<class T>
void link<T>::Delete(DataType i) //ɾ
{
	node<T>* e = index(p_head, i);
	e->pre->next = e->next;
	e->next->pre = e->pre;
	delete e;
	cout << "ɾ�����" << endl;
}

template<class T>
void link<T>::xiu_gai(DataType i) //�޸�
{
	node<T>* p = index(p_head, i);
	int num;
	cout << "�������������֣�";
	cin >> num;
	p->a = num;
	cout << "�޸����" << endl;
}

template<class T>
void link<T>::take_though() //����
{
	int num;
	cout << "��������Ҫ���ҵ����֣�";
	cin >> num;
	node<T>* p = p_head->next;
	node<T>* pp = p_head->pre;
	while (p!=p_head||pp!=p_head)
	{
		if (p->a == num||pp->a==num)
		{
			cout << "�Ѳ鵽,��Ҫ������" << p->a << "��������" << endl;
			break;
		}
		p = p->next;
		pp = pp->pre;
		if (pp == p)
		{
			cout << "����û�е�ǰԪ��" << endl;
			break;
		}
	}
}



//�����±�
template<class T>
node<T> * link<T>::index(node<T>* p_head, DataType i) //�����±�
{
	if (i<-1 || i>size - 1)
	{
		cout << "�±����Խ��" << endl;
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


//��ӡ����

template< class T>
void link<T>::disp()
{
	node<T>* p = p_head->next;
	cout << "�����У�";
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