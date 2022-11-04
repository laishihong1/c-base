#include<iostream>
using namespace std;

template<class T1,class T2>
class link;

template<class T1, class T2>
class node
{
	friend class link<T1,T2>;
 public:
	 node<T1, T2>(node<T1, T2>* p = NULL) { next = p; }  //���ڴ���ͷ�ڵ�
	 node<T1, T2>(const T1& i, const T2& j, node<T1, T2>* p = NULL) : a(i), b(j),next(p){}//���ڴ����ڵ�
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
	 node<T1, T2>* adds(int); //����
	void insert(int i, const T1& name, const T2& age); //input
	void Delete(int);//ɾ
	node<T1, T2>* index(node<T1, T2>* p_head,int i);
	void xiu_gai(int);
	void getdata(int);//��
	void ni_zhi();//���õ�����
	void Delete_max();//ɾ�������
	void pai_xu();//��������
	int num_index(int);
	 void disp();
	int Size()const;
private:
	 int size;
	 node<T1, T2>* p_head; //ͷָ��
};

//��ʼ��
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

//�����������
template<class T1, class T2>
node<T1, T2>* link<T1, T2>::adds(int length) //����
{
	node<T1, T2>* pre;
	pre = p_head;
	while(size<length)
	{
		string name;
		cout << "����������";
		cin >> name;
		int ages;
		cout << "�������䣺";
		cin >> ages;
		node<T1, T2>* pp = new node<T1, T2>(name, ages);
		pre->next = pp;
		pre = pp;
		size++;
	}
	return p_head;
}

//��������
template<class T1, class T2>
void link<T1, T2>::insert(int i,const T1&name,const T2&age)//����
{
	if (i<-1 || i>size - 1)
	{
		cout << "������Ĳ�������ȷ" << endl;
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
	cout << "�������ݽ��������Ϊ��";
	pai_xu();
}

//ɾ������
template<class T1, class T2>
void link<T1, T2>::Delete(int i)//ɾ
{
	if (i<-1 || i>size)
	{
		cout << "��������" << endl;
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

//����ָ���ڵ�
template<class T1, class T2>
node<T1, T2>* link<T1, T2>::index(node<T1, T2>* p_head,int i)
{
	if (i<-1 || i>size)
	{
		cout << "������Ĳ�������ȷ" << endl;
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

//�޸�ָ���±������
template<class T1, class T2>
void link<T1,T2>::xiu_gai(int i)
{
	node<T1, T2>* p = index(p_head, i);
	int choice;
	cout << "�����޸�ʲô��1.������2.����";
	cin >> choice;
	if (choice == 1)
	{
		string names;
		cout << "�����µ�����";
		cin >> names;
		p->a = names;
		cout << "�޸����" << endl;;
	}
	else if (choice == 2)
	{
		int Age;
		cout << "��������" << endl;
		cin >> Age;
		p->b = Age;
		cout << "�޸����" << endl;
	}
}


//ȡ������
template<class T1, class T2>
void link<T1, T2>::getdata(int i)//��
{
	if (i<-1 || i>size)
	{
		cout << "�±��д���" << endl;
		exit(0);
	}
	node<T1, T2>* p = index(p_head, i);
	if (p != NULL)
	{
		cout << "������" << p->a << " " << "���䣺" << p->b << endl;
	}	
}

template<class T1,class T2>
void link<T1, T2>::ni_zhi()//���õ�����
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


//ɾ�������
template<class T1,class T2>
void link<T1, T2>::Delete_max()//ɾ�������
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

//��������
template<class T1,class T2>
void link<T1, T2>::pai_xu()//��������
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


//�����±�
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

//����������
template<class T1, class T2>
int link<T1, T2>::Size()const
{
	return size;
}

//��ӡ
template<class T1,class T2>
void link<T1,T2>::disp()
{
	node<T1, T2>* p = adds(Size())->next;
	
	while (p != NULL)
	{
		cout<<"������" << p->a << " " <<"���䣺"<< p->b << " " << endl;
		p = p->next;
	}
}

//������
int main()
{
	link<string,int>l;
	l.adds(2); //�����������
	l.disp();
	cout << endl;
	l.insert(1, "ls", 19); //��������
	cout << endl;
	l.ni_zhi();          //��������
	cout << endl;
	l.Delete(1);      //ɾ���±�Ϊ1����Ԫ��
	l.disp();
	cout << endl;
	l.getdata(1);      //ȡ���±�Ϊ1��Ԫ��
	cout << endl;
	l.xiu_gai(1);      //�޸��±�Ϊ1��Ԫ��
	l.disp();
	cout << endl;
	l.Delete_max();      //ɾ�����ֵ
	l.disp();
	return 0;
}