#include<iostream>
using namespace std;
struct students
{
	string xue_hao;
	string name;
	string sex;
	int ages=0;
	string sheng_ri;
	int sheng_gao=0;
	string Class;
	string health;
};
typedef students DataType;
#include"student.h"
int main()
{
	SeqList array(100);
	students s[4] = { 
		{"12001","����"," ��",18,"1995 - 1" , 180 ,"   ��1 ","  ����   "},
		{"12002","����"," Ů",19,"1994 - 2" , 168 ,"   ��2 ","  һ��   "},
		{"12003","����"," ��",19,"1994 - 3" , 178 ,"   ��3  "," ����   " },
		{"12004","�ƾ�"," Ů",18,"1995 - 4 ", 165 ,"   ��4  "," ��˥�� "}
	};
	for (int i = 0; i < 4; i++)
	{
		array.insert(s[i], i);
	}
	array.Delete1();
	array.look_at();
	array.pai_xu();
	cout << endl;
	array.display();
	return 0;
}