//ȱ�ݣ�ֻ������0-9�����֣��ȴ��޸�

#include<iostream>
#include<cctype>
using namespace std;
#include"Stack.h"
#include<string>
int main()
{
	Stack<char>s;
	string m_Array;
	cout << "��������ʽ��";
	cin >> m_Array;
	const char* Array = m_Array.c_str();
	int size = m_Array.size();
	s.pin_zhuang(Array,size);
	s.disp();
	return 0;
}