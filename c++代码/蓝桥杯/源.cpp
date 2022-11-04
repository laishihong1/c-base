#include <iostream>
using namespace std;
int main()
{
    // 请在此输入您的代码
   
    float size = 0;
    int n;
    cin >> n;
    float size1 = 0;
    float* Array = new float[n];
    for (int i = 1; i <=n; i++)
    {
        cin >> Array[i];
    }

    for (int i = 1; i <=n; i++)
    {
        if (Array[i] >= 60 && Array[i] < 85)
        {
            size++;
        }
        else if (Array[i] >= 85)
        {
            size1++;
        }
    }
    float baifen = float((size / n)) * 100;
    float baifen1 = float((size1 / n))*100;

    cout << (int)baifen+1<< "%" << endl;
    cout<<(int)baifen1+1<<"%" << endl;

}