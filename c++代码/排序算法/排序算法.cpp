#include<iostream>
using namespace std;

//初级冒泡
void mao_pao(int Array[], int size)
{
	int count1 = 0,count2=0;
	int temp = 0;

	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1 ; j < size; j++)
		{
			count1++;
			if (Array[i] > Array[j])
			{
				count2++;
				temp = Array[j];
				Array[j] = Array[i];
				Array[i] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "一共循环了" << count1 << "次，排序了" << count2 << "次" << endl;
}

//改进冒泡
void mao_pao2(int Array[], int size)
{
	int count1 = 0, count2 = 0;
	int temp = 0;
	int flag = 1;
	for (int i = 0; i < size - 1&&flag; i++)
	{
		flag = 0;
		for (int j = size-1; j>i; j--)
		{
			count1++;
			if (Array[j] > Array[j + 1])
			{
				flag = 1;
				count2++;
				temp = Array[j];
				Array[j] = Array[j + 1];
				Array[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "一共循环了" << count1 << "次，排序了" << count2 << "次" << endl;
}

//选择排序
void xuan_ze(int Array[], int size)
{
	int i, j, min, temp;
	int count1 = 0, count2 = 0;
	for (i = 0; i < size - 1; i++)
	{
		count1++;
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (Array[j] < Array[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			temp = Array[min];
			Array[min] = Array[i];
			Array[i] = temp;
			count2++;
		}
	}
	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "一共循环了" << count1 << "次，排序了" << count2 << "次" << endl;
}

//直接插入排序
void InsertSorts(int Array[],int size)
{
	int i, j;
	for (i = 2; i <= size; i++)
	{
		if (Array[i] < Array[i - 1])
		{
			Array[0] = Array[i];
			for (j = i - 1; Array[0] < Array[j]; j--)
			{
				Array[j + 1] = Array[j];
			}
			Array[j + 1] = Array[0];
		}
	}
}

//折半插入排序
void BinsertSort(int Array[], int size)
{
	int low = 1;
	int high;
	int mid;
	for (int i = 2; i < size; i++)
	{
		high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (Array[0] < Array[mid])
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		for (int j = i - 1; j >= high + 1; j--)
			Array[j + 1] = Array[j];
			Array[high + 1] = Array[0];
	}
}

//希尔排序
void InserSort(int Array[], int size)
{
	int i, j, temp;
	int count1 = 0, count2 = 0;
	int gap = size;
	do
	{
		gap = gap / 3 + 1;
		for (i = gap; i < size; i++)
		{
			count1++;
			if (Array[i] < Array[i - gap])
			{
				temp = Array[i];
				for (j = i - gap; Array[j] > temp; j -= gap)
				{
					Array[j + 1] = Array[j];
				}
				Array[j + 1] = temp;
				count2++;
			}
		}
	}while(gap>1);

	for (int i = 0; i < size; i++)
	{
		cout << Array[i] << " ";
	}
	cout << "一共循环了" << count1 << "次，排序了" << count2 << "次" << endl;
}

//堆排序
void swap(int Array[], int i, int j)
{
	int temp;
	temp = Array[i];
	Array[i] = Array[j];
	Array[j] = temp;
}
void HeapAdjust(int Array[], int s, int n)
{
	int i, temp;
	temp = Array[s];
	for (i = 2 * s; i <= n; i *= 2)
	{
		if (i < n && Array[i] < Array[i + 1])
		{
			i++;
		}
		if (temp >= Array[i])
		{
			break;
		}
		Array[s] = Array[i];
		s = i;
	}
	Array[s] = temp;
}
void HeapSort(int Array[], int size)
{
	int i;
	for (i = size / 2; i > 0; i--)
	{
		HeapAdjust(Array, i, size);
	}
	for (i = size; i > 1; i--)
	{
		swap(Array, 1, i);
	}
	swap(Array, 1, i);
	HeapAdjust(Array, 1, i - 1);
}



int main()
{
	int Array[10] = {1,5,6,4,7,8,3,10,3};

	/*mao_pao(Array, 10);  */    //45 21

	/*mao_pao(Array, 10); */ //45 21
	
	xuan_ze(Array, 10); 

	return 0;
}