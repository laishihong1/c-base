
#include<iostream>
using namespace std;
struct student
{
	int num;
};
typedef student DataType;

#include"SeqList.h"

void choice1();

int main()
{
	
	choice1();
	return 0;
}
void choice1()
{
	SeqList s(100);
	while (true)
	{
		int choice;
		cout << "1.输入数据" << endl;
		cout << "2.输出数据" << endl;
		cout << "3.查找元素下标" << endl;
		cout << "4.指定删除元素 *" << endl;
		cout << "5.就地逆置元素 *" << endl;
		cout << "6.元素排序" << endl;
		cout << "7.删除数组所有一样的元素" << endl;
		cout << "0.退出循环" << endl;
		cout << "********" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			s.input();
			break;
		case 2:
			s.display();
			break;
		case 3:
			s.look_at();
			break;
		case 4:
			s.disx();
			break;
		case 5:
			s.ni_zhi();
			break;
		case 6:
			s.pai_xu();
			break;
		case 7:
			s.zhi_ding_shan_chu();
			break;
		case 0:
			exit(0);
			break;
		default:
			break;
		}
		
		system("pause");
		system("cls");
     }
}

