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
		cout << "数组已满" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "i下标不符合" << endl;
		exit(0);
	}
	list[size] = item;
	size++;
}

void SeqList::display()
{
	if (list == NULL)
	{
		cout << "数组为空" << endl;
	}
	else {
		cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t"
			 << "年龄" << "\t" << "生日" << "\t" << "身高" << "\t"
			 << "班级" << "\t" << "健康状况" << "\t" << endl;
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
	
		cout << "你想通过哪项来进行学生查找？" << endl;
		cout << "1.学号；2.姓名" << endl;
		cin >> choice;
		if (choice == 1)
		{
			string Xue_Hao;
			cout << "输入学号：";
			cin >> Xue_Hao;
			for (int i = 0; i < size; i++)
			{
				if (Xue_Hao == list[i].xue_hao)
				{
					cout << "已查找到当前学生信息" << endl;
					cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t"
						<< "年龄" << "\t" << "生日" << "\t" << "身高" << "\t"
						<< "班级" << "\t" << "健康状况" << "\t" << endl;
					cout << list[i].xue_hao << "\t" << list[i].name << " \t" << list[i].sex << " \t"
						<< list[i].ages << "  " << list[i].sheng_ri<<"\t" << list[i].sheng_gao << "  " << list[i].Class
						<< "  " << list[i].health << endl;
					break;
				}
				else {
					cout << "没有此学生的信息" << endl;
				}
			}
		}

		else if (choice == 2)
		{
			string Xing_ming;
			cout << "输入学号：";
			cin >> Xing_ming;
			for (int i = 0; i < size; i++)
			{
				if (Xing_ming == list[i].name)
				{
					cout << "已查找到当前学生信息" << endl;
					cout << "学号" << "\t" << "姓名" << "\t" << "性别" << "\t"
						<< "年龄" << "\t" << "生日" << "\t" << "身高" << "\t"
						<< "班级" << "\t" << "健康状况" << "\t" << endl;
					cout << list[i].xue_hao << "  " << list[i].name << " " << list[i].sex << " "
						<< list[i].ages << list[i].sheng_ri << " " << list[i].Class
						<< " " << list[i].health << endl;
					break;
				}
				else 
				{
					cout << "没有此学生的信息" << endl;
				}
			}
		}
}


void SeqList::Delete1()
{
	int choice;
	
		cout << "你想通过查找哪项来删除学生信息？" << endl;
		cout << "1.学号；2.姓名" << endl;
		cin >> choice;
		if (choice == 1)
		{
			string Xue_Hao;
			cout << "输入学号：";
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
			cout << "已删除" << endl;
			size--;
		}

		else if (choice == 2)
		{
			string Xing_ming;
			cout << "输入学号：";
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
			cout << "已删除" << endl;
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