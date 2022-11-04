//缺陷：只能输入0-9的数字，等待修改

#include<iostream>
#include<cctype>
using namespace std;
#include"Stack.h"
#include<string>
int main()
{
	Stack<char>s;
	string m_Array;
	cout << "请输入表达式：";
	cin >> m_Array;
	const char* Array = m_Array.c_str();
	int size = m_Array.size();
	s.pin_zhuang(Array,size);
	s.disp();
	return 0;
}