#include<iostream>
using namespace std;
#include"list.h"
int main()
{
    calcolator c;
   /* int n;
    cout << "输入数据：";
    cin >> n;
    int nn;
    cout << "输入选择(1. 10进制，2. 2进制，3. 8进制 ，4. 16进制)：";
    cin >> nn;
    if (nn == 1)
    {
        
    }

    else if (nn == 2)
    {
        string number = to_string(n);
    
    }

    else if (nn == 3)
    {
       
    }

    else if (nn == 4)
    {
       
    }*/
   
   /* c.zhuan_huan3("2021ABCD", 10); */             //16进制随意转换
   /* c.zhuan_huan(100, 8); */               //10进制数随意转换
    c.zhuan_huan1("00100000", 10);         //2 进制随意转换
    //c.zhuan_huan2(66, 16);              //8 进制随意转换
    return 0;
}
