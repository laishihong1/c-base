#include<iostream>
using namespace std;
#include"link_list.h"

int main()
{
	Links<int>mylist;
	int array[9]={1,2,3,4,5,6,7,8,9};
	int n=9;
	
	for(int i=0;i<n;i++)
	{
	mylist.Insert(array[i],i);
	}
	
	mylist.Delete(4);
	for(int i=0;i<mylist.Size();i++)
	{
      int temp=mylist.getData(i);
      cout<<temp<<" ";
	}

}