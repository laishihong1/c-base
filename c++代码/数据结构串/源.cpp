#include<iostream>
#include<cctype>
using namespace std;

typedef struct strandNode
{
	struct strandNode* next=NULL;
	char node;
}TypeNode;

class String
{
   public:
	   String();
	  ~String();
	   TypeNode* Strcpy(TypeNode*, const char*);
	   TypeNode* Concat(TypeNode*,TypeNode*);
	   int StrCompare(TypeNode*, TypeNode*);
	   TypeNode* StrInsert(TypeNode*, int pos, TypeNode*);
	   void disp(TypeNode* P_head);
	   int TypeNodeSize(TypeNode* p);
	   int StrComparison(TypeNode*, TypeNode*); //BF�㷨
	   int StrComparison1(TypeNode*, TypeNode*);//KMP�㷨
	   int* Next(TypeNode*);
   private:
	   TypeNode* link( const char*);
	   int strandNodeSize;
	   TypeNode* p_head;
};
 
String::String()
{
	p_head = new TypeNode();
	this->strandNodeSize = 0;
 }
String::~String()
{
	TypeNode* p = this->p_head->next;
	while (p != NULL)
	{
		p = this->p_head->next;
		delete p_head;
		p_head = p;
	}
}

TypeNode* String::Strcpy(TypeNode* Array1, const char*Array2)
{
	if (!isalnum(Array1[0].node) && !isspace(Array1[0].node))
	{
		Array1 = link(Array2);
		return Array1;
	}
	else {
		cout << "����Strcpy�ĵ�һ����������һ���յ��ַ�����" << endl;
		exit(0);
	}
}

TypeNode* String::Concat(TypeNode*Array1, TypeNode*Array2)
{
	TypeNode* newArray = new TypeNode();
	TypeNode* p = newArray;
	TypeNode* p1 = Array1->next;
	TypeNode* p2 = Array2->next;
	while (true)
	{
		if (p1 != NULL)
		{
			TypeNode* node = new TypeNode();
			node->node = p1->node;
			p->next = node;
			p = node;
			p1 = p1->next;
		}
		if (p1 == NULL)
		{
			while (p2 != NULL)
			{
				TypeNode* node = new TypeNode();
				node->node = p2->node;
				p->next = node;
				p = node;
				p2 = p2->next;
			}
			Array1 = newArray;
			break;
		}
	}
	 return Array1;
}

int String::StrCompare(TypeNode*Array1, TypeNode*Array2)
{
	 int i = 0;
	 TypeNode* p1 = Array1->next;
	 TypeNode* p2 = Array2->next;
	 while (i < this->TypeNodeSize(Array1) && i < this->TypeNodeSize(Array2))
	 {
		 if ((int)(p1->node) > (int)(p2->node))
		 {
			 return 1;
		 }
		 if ((int)(p1->node) < (int)(p2->node))
		 {
			 return -1;
		 }
		 if ((int)(p1->node)==(int)(p2->node))
		 {
			 ++i;
			 p1 = p1->next;
			 p2 = p2->next;
			 continue;
		 }
		 ++i;
		 p1 = p1->next;
		 p2 = p2->next;
	 }
	 if (i == this->TypeNodeSize(Array1) && i!= this->TypeNodeSize(Array2))
	 {
		 return -1;
	 }
	 else if (i != this->TypeNodeSize(Array1) && i == this->TypeNodeSize(Array2))
	 {
		 return 1;
	 }
	 else
	 {
		 return 0;
	 }
}

TypeNode* String::StrInsert(TypeNode* Array1, int pos, TypeNode* Array2)
{
	TypeNode* p = Array1->next;
	TypeNode* p1 = Array2->next;
	TypeNode* p_node = new TypeNode();
	TypeNode* pp = p_node;
	int i = 0;
	if (pos < this->TypeNodeSize(Array1))
	{
		while (true)
		{
			if (i == pos)
			{
				while (p->next != NULL)
				{
					TypeNode* node = new TypeNode();
					node->node = p->node;
					pp->next = node;
					pp = node;
					p = p->next;
				}
				while (p1 != NULL)
				{
					TypeNode* node = new TypeNode();
					node->node = p1->node;
					p->next = node;
					p = node;
					p1 = p1->next;
				}
				break;
			}
			i++;
			p = p->next;
		}
		TypeNode* P_head = p_node->next;
		while (P_head != NULL)
		{
			TypeNode* node = new TypeNode();
			node->node = P_head->node;
			p->next = node;
			p = node;
			P_head = P_head->next;
		}
	}
	return Array1;
}

TypeNode* String::link(const char*c)
{
	int size = strlen(c);
	TypeNode* pHead = this->p_head;
	for (int i = 0; i < size; i++)
	{
		TypeNode* p = new TypeNode();
		p->node = c[i];
		pHead->next = p;
		pHead = p;
	}
	return this->p_head;
}

void String::disp(TypeNode*P_head)
{
	TypeNode* p = P_head->next;
	while (p != NULL)
	{
		cout << p->node;
		p = p->next;
	}
	cout << endl;
}

int String::TypeNodeSize(TypeNode*p)
{
	int size = 0;
	TypeNode* pp = p->next;
	while (true)
	{
		if (pp != NULL)
		{
			size++;
			pp = pp->next;	
		}
		else {
			break;
		}
	}
	return size;
}

//BF�㷨
int String::StrComparison(TypeNode*Str1, TypeNode*Str2) 
{
	TypeNode* p1 = Str1->next;  //p1�ƶ�ָ��
	TypeNode* P1 = Str1->next;  //��ֵ��p1ָ��
	TypeNode* p2 = Str2->next;  //p2ָ���ƶ�

	while (p1 != NULL)
	{
		if (p2->node != p1->node)
		{
			p2 = Str2->next;   //�����������ƥ�䣬��ô�Ͱ�p2ָ�����¸�λ���ʼ
			P1 = P1->next;     //P1ָ���������Ѿ�������һ�Σ����Ӵ�����������һ��Ԫ��һ����ƥ�ԣ�P1ָ��������λ��
			if (P1 == NULL)
			{
				break;
				return -1;
			}
			p1 = P1;           //��Ϊp1ָ��Ҫ������ƶ��������Ӵ�������������һ��Ԫ�ز�ƥ�ԣ��Ͱ�P1ָ�����¸�ֵ��p1;
			continue;
		}
		  p1 = p1->next;
		  p2 = p2->next;
	     if (p2 == NULL)
		 {
			break;
			return 1;
		 }
		 else if (p1 == NULL && p2 == NULL)
		 {
			 break;
			 return 0;
		 }	
	}
	return 0;
}

//��Next����
int * String::Next(TypeNode*Str)
{
	int i=0;
	int j=0;
	char* Array= new char[this->TypeNodeSize(Str) + 2]; //����һ��char����������Str1���������
	int* Nexts = new int[this->TypeNodeSize(Str) + 2];  //����ǰ׺ֵ
	Nexts[0] = 0;
	TypeNode* p1 = Str->next;  //p1�ƶ�ָ��
	while (p1 != NULL)
	{
		Array[i]= p1->node;
		i++;
		p1 = p1->next;
	}
	
	for (int k = 1; k <i; k++)
	{
		while (j>0&&Array[j] != Array[k])
		{
			j = Nexts[j - 1];
		}
		if (Array[j] == Array[k])
		{
			j++;
		}
		Nexts[k] = j; //0 1 0 1 2 0
	}
	for (int s = 0; s < i; s++)
	{
		cout << Nexts[s] << " ";
	}
	return Nexts;
}

//KMP�㷨
int String::StrComparison1(TypeNode*Str1, TypeNode*Str2)
{
	char*Array1=new char[(this->TypeNodeSize(Str1)+2)]; //����һ��char����������Str1���������
	TypeNode* p1 = Str1->next;  //p1�ƶ�ָ��
	int i = 0;
	int j = 0;
	int m = 0;
	
	while (p1 != NULL)
	{
		Array1[i]= p1->node;
		i++;
		p1 = p1->next;
	}
	TypeNode* p2 = Str2->next;  //p2ָ���ƶ�
	char* Array2 = new char[(this->TypeNodeSize(Str2)+2)];//����һ��char����������Str2���������
	while (p2 != NULL)
	{
		Array2[j] = p2->node;
		j++;
		p2 = p2->next;
	}

	/* i = 0;
	 j = 0;*/

	/*while (true)
	{
		if (i==0&&j==0)
		{
			if(Array1[i] != Array2[j])
			{
				i++;
			}
		}
		
	flag:
		if (Array1[i] != Array2[j])
		{
			while (true)
			{
				k = i - 1;
				if (Array2[k]==Array2[m])
				{
					j = 0;
					i = k;
					break;
					goto flag;
				}
				m++;
				k--;
			}	
		}
		if (i + 1 > this->TypeNodeSize(Str1))
		{
			break;
			return -1;
		}

		else if (j+2 > this->TypeNodeSize(Str2))
		{
			break;
			return 1;
		}
		j++;
		i++;
	}*/

	int* Next = this->Next(Str2);
	for (int k = 0; k < this->TypeNodeSize(Str1); k++)
	{
		 if (Array1[k] == Array2[m])
		{
			m++;
			continue;
		}

		else if (k + 1 > this->TypeNodeSize(Str1))
		{
			return -1;
		}

		else if (m + 1 > this->TypeNodeSize(Str2))
		{
			return 1;
	
		}

		 if (Array1[k] != Array2[m])
		 {
			 m = Next[m - 1];
			 k = k - 1;
			 continue;
		 }
	}
	return 0;
}


int main()
{
	String s;
	String s1;
	TypeNode* ss=new TypeNode();
	TypeNode* ss1 = new TypeNode();
	cout << "�������ַ�����";
	char Array[10];
	char Array1[10];
	cin >> Array;
	cin >> Array1;
	ss=s.Strcpy(ss,Array);
	ss1 = s1.Strcpy(ss1, Array1);

	/*s.disp(ss);
	ss=s.Concat(ss, ss1);
	s.disp(ss);*/

	/*int max=s.StrCompare(ss, ss1);
	if (max == 1)
	{
		cout << "�ַ���ss�ϴ�" << endl;
	}
	else if (max == -1)
	{
		cout << "�ַ���ss1�ϴ�" << endl;
	}
	else
	{
		cout << "ss��ss1һ����" << endl;
	}*/

	ss=s.StrInsert(ss, 2, ss1);
	int judge = s.StrComparison1(ss, ss1);
	if (judge > 0)
	{
		cout << "�Ӵ�����������" << endl;
	}
	else if (judge < 0)
	{
		cout << "�Ӵ�������������" << endl;
	}
	else if (judge == 0)
	{
		cout << "�Ӵ�����������,�����������Ӵ����" << endl;
	}
	
  /*s.disp(ss);*/

	return 0;
}