#include<iostream>
using namespace std;
struct node
{
	int age;
	node* next;
}Node,*link; //������һ��ͷָ��link��һ���Զ���Node;

//д������(��)
node*tou_cha(int n)
{
	node* head =(node*)malloc(sizeof(node));
	link = head;
	link->next = NULL;
	
	for (int i = 0; i < n; i++)
	{
		node* p_next =(node*)malloc(sizeof(node));
		if (p_next != NULL)
		{
			p_next->age = i;
			link->next = p_next;
			link = p_next;
			link->next = NULL;
		}	
		
	}
	cout << "���������" << endl;
	return head;
}

//�鿴����
void cha_kan( node* p_head)
{
	node* p;
	p = p_head->next;
	while (p != NULL)
	{
		cout << p->age << " ";
		p = p->next;
	}
	cout << "�������������������Ԫ��" << endl;
}

//���ص�n���ڵ㣬�෴���Ҳ���Ԫ�أ��ͷ���ͷ�ڵ�
node* index(node*p_head,int i)
{
	node* p = p_head->next;
	while (p != NULL)
	{
		if (p->age == i)
		{
			return p;
			break;
		}
		p = p->next;//��Ҫ��һ��
	}
	return p_head;
}

//����ڵ㣬����ҵõ�����Ԫ�أ��ͽ��µ�Ԫ�ز���Ѱ��Ԫ�غ��棬�෴���Ҳ���Ԫ�أ��Ͱ�Ԫ�ز嵽��ǰ��
void insert(node* p_head,int i)
{
	node* p = index(p_head, i);
 if (p != NULL)
	{
		node* s = (node*)malloc(sizeof(node));
	
			int nums;
			cout << "�������֣�";
			cin >> nums;
			s->age = nums;
			s->next = p->next;
			p->next = s;
	}
	cout << "�������" << endl;
}

//ɾ��ָ���ڵ�(ɾ)
void Delete(node* p_head, int i)
{
	node* p = index(p_head, i);
	node* s = p_head;

	while (s != NULL)
	{
		if (s->next->age == p->age)
		{
			s->next = p->next;
			break;
		}
		s = s->next;
	}
	cout << "ɾ�����" << endl;
}

//�޸�����
void xiu_gai(node*p_head,int i)
{
	node* p = index(p_head, i);
	int num;
	cout << "�����޸�����";
	cin >> num;
	p->age = num;
}

int main()
{
	node* head = tou_cha(5);
	cha_kan(head);
	cout << "�������ĸ����ֺ����������" << endl;
	int i;
	cin >> i;
	insert(head,i);
	cha_kan(head);
	cout << "����ɾ���ĸ�����" << endl;
	int n;
	cin >> n;
	Delete(head, n);
	cha_kan(head);

	cout << "��Ҫ�޸��ĸ�����" << endl;
	int wei_zhi;
	cin >> wei_zhi;
	xiu_gai(head, wei_zhi);
	cha_kan(head);



	return 0;
}
