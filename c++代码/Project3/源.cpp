#include<iostream>
using namespace std;

int main()
{	
	int array[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> array[i][j];
		}
	}
	int total = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			total+= array[i][j];
		}
	}
	cout << total << endl;

	return 0;
	
}