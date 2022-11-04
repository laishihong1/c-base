#include<iostream>
using namespace std;
typedef struct leaf
{
	int weight=0;
	int lfag=0,rfag=0;
	char data;
}Leaf;

void create(Leaf*shu_zu,int size)
{
	char c;
	int weight=0;
	int total=0;
	for (int i = 1; i==size; i++)
	{
		cin >> c;
		shu_zu[i].data = c;
		cin >> weight;
		shu_zu[i].weight = weight;
	}
	shu_zu=maopao(shu_zu, size);
}

Leaf* weights(Leaf* shu_zu, int size)
{
	
}

Leaf* maopao(Leaf*shu_zu, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i; j < size - i - 1; j++)
		{
			if (shu_zu[j].weight > shu_zu[j+1].weight)
			{
				int temp = shu_zu[j].weight;
				char c = shu_zu[j].data;
				shu_zu[j].weight = shu_zu[j + 1].weight;
				shu_zu[j].data = shu_zu[j + 1].data;
				shu_zu[j + 1].weight = temp;
				shu_zu[j + 1].data = c;
			}
		}
	}
	return shu_zu;
}

int main()
{
	int size;
	cout << "你要创建几个节点：";
	cin >> size;
	Leaf* Array = new Leaf[(size*2)+1];
	create(Array,size);
	return 0;
}