#pragma once
#include<iostream>

using namespace std;
class SeqList
{
protected:
	DataType* list;
	int maxsize;
	int size;
public:
	SeqList(int max);//
	~SeqList(void);
	void display();//
	void look_at();//
	void insert(const DataType& item, int);//
    void Delete1();//
	void pai_xu();//
};

SeqList::SeqList(int max)
{
	this->maxsize = max;
	size = 0;
	list = new DataType[maxsize];
}
SeqList::~SeqList(void)
{
	delete[]list;
}

void SeqList::insert(const DataType& item, int i)
{
	if (size == maxsize){
		cout << "��������" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "i�±겻����" << endl;
		exit(0);
	}
	list[size] = item;
	size++;
}

void SeqList::display()
{
	if (list == NULL)
	{
		cout << "����Ϊ��" << endl;
	}
	else {
		cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t"
			 << "����" << "\t" << "����" << "\t" << "���" << "\t"
			 << "�༶" << "\t" << "����״��" << "\t" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << list[i].xue_hao << "\t" << list[i].name << " \t" << list[i].sex << " \t"
				<< list[i].ages << "  " << list[i].sheng_ri<<"\t" << list[i].sheng_gao << "  " << list[i].Class
				<< "  " << list[i].health << endl;
		}
	}
	
}

void SeqList::look_at()
{
	int choice;
	
		cout << "����ͨ������������ѧ�����ң�" << endl;
		cout << "1.ѧ�ţ�2.����" << endl;
		cin >> choice;
		if (choice == 1)
		{
			string Xue_Hao;
			cout << "����ѧ�ţ�";
			cin >> Xue_Hao;
			for (int i = 0; i < size; i++)
			{
				if (Xue_Hao == list[i].xue_hao)
				{
					cout << "�Ѳ��ҵ���ǰѧ����Ϣ" << endl;
					cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t"
						<< "����" << "\t" << "����" << "\t" << "���" << "\t"
						<< "�༶" << "\t" << "����״��" << "\t" << endl;
					cout << list[i].xue_hao << "\t" << list[i].name << " \t" << list[i].sex << " \t"
						<< list[i].ages << "  " << list[i].sheng_ri<<"\t" << list[i].sheng_gao << "  " << list[i].Class
						<< "  " << list[i].health << endl;
					break;
				}
				else {
					cout << "û�д�ѧ������Ϣ" << endl;
				}
			}
		}

		else if (choice == 2)
		{
			string Xing_ming;
			cout << "����ѧ�ţ�";
			cin >> Xing_ming;
			for (int i = 0; i < size; i++)
			{
				if (Xing_ming == list[i].name)
				{
					cout << "�Ѳ��ҵ���ǰѧ����Ϣ" << endl;
					cout << "ѧ��" << "\t" << "����" << "\t" << "�Ա�" << "\t"
						<< "����" << "\t" << "����" << "\t" << "���" << "\t"
						<< "�༶" << "\t" << "����״��" << "\t" << endl;
					cout << list[i].xue_hao << "  " << list[i].name << " " << list[i].sex << " "
						<< list[i].ages << list[i].sheng_ri << " " << list[i].Class
						<< " " << list[i].health << endl;
					break;
				}
				else 
				{
					cout << "û�д�ѧ������Ϣ" << endl;
				}
			}
		}
}


void SeqList::Delete1()
{
	int choice;
	
		cout << "����ͨ������������ɾ��ѧ����Ϣ��" << endl;
		cout << "1.ѧ�ţ�2.����" << endl;
		cin >> choice;
		if (choice == 1)
		{
			string Xue_Hao;
			cout << "����ѧ�ţ�";
			cin >> Xue_Hao;
			for (int i = 0; i < size; i++)
			{
				if (Xue_Hao == list[i].xue_hao)
				{
					for (int j = i; j < size; j++)
					{
						list[j] = list[j + 1];
					}
				}
			}
			cout << "��ɾ��" << endl;
			size--;
		}

		else if (choice == 2)
		{
			string Xing_ming;
			cout << "����ѧ�ţ�";
			cin >> Xing_ming;
			for (int i = 0; i < size; i++)
			{
				if (Xing_ming == list[i].name)
				{
					for (int j = i; j < size; j++)
						{
							list[j] = list[j + 1];
						}
				}
			}
			cout << "��ɾ��" << endl;
			size--;
		}
}

void SeqList::pai_xu()
{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size - 1; j++)
				{
					if (list[j].xue_hao > list[j + 1].xue_hao)
					{
						DataType x = list[j];
						list[j] = list[j+1];
						list[j + 1] = x;
					}
				}
			}
}