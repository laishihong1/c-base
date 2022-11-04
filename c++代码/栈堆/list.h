#pragma once
#include<iostream>
#include<string>
#include<math.h>
#include<cctype>
using namespace std;

class arrays
{
	friend class calcolator;
public:
	arrays() { next = NULL; num = '\0'; }
	arrays(int m_num) : num(m_num) { next = NULL; }
	~arrays() {}
private:
	arrays* next;
	int num;
};

class calcolator
{
public:
	calcolator();
	void zhuan_huan(int num, int num1);
	void zhuan_huan1(string num, int num1);
	void zhuan_huan2(int num, int num1);
	void zhuan_huan3(string num,int num1);
	string wei_shu(int num);        //返回数字每一位上的数字
	void disp();
private:
	int size;
	arrays* p_head;
};

calcolator::calcolator()      //创建一个头节点 
{
	this->p_head = new arrays();
	this->size = 0;
}

void calcolator::zhuan_huan(int num, int num1)
{
	arrays* p = this->p_head;
	int number = num;
	int number1 = 0;
	while (true)
	{
		number1 = number % num1;     //0  //1  //0
		number = number / num1;     //5  //2  //1
		arrays* pre = new arrays(number1);
		pre->next = p;
		p = pre;
		if (number == 1||number==0)
		{
			break;
		}
		this->size++;
	}
	if (number == 1)
	{
		arrays* pre = new arrays(number);
		pre->next = p;
		p = pre;
		this->size++;
	}
	this->p_head = p;
	disp();
}

void  calcolator::zhuan_huan1(string num, int num1)
{
	int total = 0;
	int size = num.size();
	for (int i = 0; i <num.size(); i++)
	{
		size--;
		total += (num[i] - '0') * int(pow(2, size));	
	}
	if (num1 == 10)
	{
		cout << total;
		exit(0);
	}
	else {
		zhuan_huan(total, num1);
	}
}

void  calcolator::zhuan_huan2(int num, int num1)
{
	string number = wei_shu(num);
	int size = number.size();
	int total = 0;
		for (int i = 0; i < number.size(); i++)
		{
			if ((number[i] - '0') >= 8)
			{
				cout << "8进制是0-7，个位到之后位数都是0-7,请重新输入" << endl;
				exit(0);
			}
			size--;
			total +=  (number[i] - '0') * int(pow(8, size));
		}
		if (num1 == 10)
		{
			cout << total << endl;
			exit(0);
	    }
		else {
			zhuan_huan(total, num1);
		}
}

void calcolator::zhuan_huan3(string num, int num1)
{
	int size = num.size();
	int total = 0;
	for (int i = 0; i < num.size(); i++)
	{
		size--;
		if (isalpha(num[i]))
		{
			total+=(10+(num[i]-'a'))*int(pow(16,size));
		}
		else {
			total += (num[i] - '0') * int(pow(16, size));
		}
	}
	if (num1 == 10)
	{
		cout << total << endl;
		exit(0);
	}
	else {
		zhuan_huan(total, num1);
	}
}

void calcolator::disp()
{
	arrays* p = this->p_head;
	int length = 0;
	char zi_mu = 'a';
	while (p != NULL)
	{
		if (p->num >= 10)
		{
			int size = p->num - 10;
			zi_mu += size;
			cout << zi_mu;	
		}
		else {
			cout << p->num;
		}

		if (++length > this->size)
		{
			break;
		}
		p = p->next;
	}
	cout << endl;
}

string calcolator::wei_shu(int num) //返回数字每一位上的数字
{
	 string number = to_string(num);
	 return number;
}








