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
		{"12001","林星"," 男",18,"1995 - 1" , 180 ,"   计1 ","  健康   "},
		{"12002","张媛"," 女",19,"1994 - 2" , 168 ,"   计2 ","  一般   "},
		{"12003","刘力"," 男",19,"1994 - 3" , 178 ,"   计3  "," 健康   " },
		{"12004","黄觉"," 女",18,"1995 - 4 ", 165 ,"   计4  "," 神经衰弱 "}
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