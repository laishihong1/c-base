#pragma once
#include<iostream>
#include<cstdlib>
using namespace std;

class SeqList
{
 protected:
	 DataType*list;
	 int maxsize;
	 int size;
 public:
	 SeqList(int max);
	 ~SeqList(void);
	 void input();
	 void display();
	 void look_at();
	 int Size()const;
	 void insert(const DataType& item,int);
	 void disx();
	 DataType Delete1(const int);
	 DataType getdata(int i)const;
	 void ni_zhi();
	 void pai_xu();
	 void zhi_ding_shan_chu();
};

SeqList::SeqList(int max)
{
	this->maxsize = max;
	this->size = 0;
	this->list = new DataType[maxsize];
}
SeqList::~SeqList(void)
{
	delete[]list;
}
void SeqList::input()
{
	int sizes;
	cout << "输入数组大小：";
	cin >> sizes;
	student* array = new student[sizes];

	for (int i = 0; i < sizes; i++)
	{
		cout << "输入第" << i + 1 << "个数：";
		cin >> array[i].num;
		this->insert(array[i], i);
	}
}
void SeqList::look_at()
{
	if (list == NULL)
	{
		cout << "数组为空" << endl;
		exit(0);
	}
	int shu_zi;
	cout << "请输入元素数字：";
	cin >> shu_zi;
	for (int i = 0; i < size; i++)
	{
		if (list[i].num == shu_zi)
		{
			cout << "此元素" << list[i].num << "的下标为：" << i << endl;
			break;
		}
		else {
			cout << "-1" << endl;
		}
	}
}
int SeqList::Size()const
{
	return size;
}
void SeqList::insert(const DataType& item, int i)
{
	if (size == maxsize)
	{
		cout << "顺序表已满" << endl;
		exit(0);
	}
	if (i<0 || i>size)
	{
		cout << "i参数越界" << endl;
	}
	for (int j = size;j+1>i; j--)
	{
		list[i] = item;
	}
	size++;
}
void SeqList::disx()
{
	int length;
	int choice;
	while (true)
	{
		cout << "1.根据元素下标删除数字" << endl;
		cout << "2.根据输入的数字删除数组里指定的元素" << endl;
		cout << "0.退出操作" << endl;
		cin >> choice;
		if (choice == 1)
		{
			int num1;
			cout << "输入元素下标：";
			cin >> num1;
			Delete1(num1);
		}
		
		if (choice == 2)
		{
			int num2;
			cout << "输入元素：";
			cin >> num2;
			for (int i = 0; i < size; i++)
			{
				if (list[i].num == num2)
				{
					 length = i;
					 for (int j = length; j < size; j++)
					 {
						 list[j] = list[j + 1];
					 }
					 this->size--;
					 cout << "已删除" << endl;
					 break;
				}
				else 
				{
					cout << "数组中没有此元素存在" << endl;
				}
			}
		}
		else 
		{
			break;
		}
		int choicess;
		cout << "是否还要删除元素" << endl;
		cout << "1.确定，2.取消" << endl;
		cin >> choicess;
		if (choicess == 1)
		{
			continue;
		}
		else {
			break;
		}
		system("pause");
		system("cls");
	}

}
DataType SeqList::Delete1(const int i)
{
	if (size == 0)
	{
		cout << "顺序表没有数据" << endl;
		exit(0);
	}
	if (i<0 || i>size - 1)
	{
		cout << "i参数越界了" << endl;
		exit(0);
	}
	DataType x = this->list[i];
	for (int j = i; j <size - 1; j++)
	{
		list[j] =list[j + 1];
	}
	cout << "已删除" << endl;
	this->size--;
	return x;
}
DataType SeqList::getdata(int i)const
{
	if (i<0 || i>size - 1)
	{
		cout << "i参数越界了" << endl;
		exit(0);
	}
	return list[i];
}
void SeqList::ni_zhi()
{
	if (list == NULL)
	{
		cout << "数组为空" << endl;
		exit(0);
	}
	int start = 0;
	int end = size-1;
	while (start < end)
	{
		int temp = list[start].num;
		list[start].num = list[end].num;
		list[end].num = temp;
		start++;
		end--;
	}
	cout << "已逆置" << endl;
}
void SeqList::zhi_ding_shan_chu()
{
	int num;
	cout << "请输入你要删除的元素：";
	cin >> num;
	DataType* array = new DataType[this->maxsize];
	int length = 0;
	for (int i = 0; i < this->size; i++)
	{
		if (this->list[i].num != num)
		{
			array[length] = this->list[i];
			length++;
		}
	}
	delete[]this->list;
	this->list = array;
	this->size = length;
	cout << "已删除" << endl;
}
void  SeqList::pai_xu()
{
	int choice;
	int choices;
	if (list == NULL)
	{
		cout << "数组为空" << endl;
		exit(0);
	}
	while (true)
	{
		cout << "你想怎么排序，1.升序；2.降序" << endl;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size - 1; j++)
				{
					if (list[j].num > list[j + 1].num)
					{
						int temp = list[j + 1].num;
						list[j + 1].num = list[j].num;
						list[j].num = temp;
					}
				}
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < size; i++)
			{
				for (int j = 0; j < size - 1; j++)
				{
					if (list[j].num < list[j + 1].num)
					{
						int temp = list[j + 1].num;
						list[j + 1].num = list[j].num;
						list[j].num = temp;
					}
				}
			}
		}
		else
		{
			break;
		}
		cout << "你想进行选择修改吗？1.NO; 2.YES" << endl;
		cin >> choices;
		if (choices == 2)
		{
			continue;
		}
		else {
			break;
		}
	}
	system("pause");
	system("cls");
}
void SeqList::display()
{
	cout << "数字有：" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << list[i].num << " ";
	}
}
