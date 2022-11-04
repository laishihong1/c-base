#include<iostream>
using namespace std;

#define MAXSIZE 100
typedef int DataType;

template<class T>
class list_array;

template<class T>
class node
{
	friend class list_array<T>;
  private:
	  T a;
	  DataType cur;
  public:
	  node(){}
	  ~node(){}
};

template <class T>
class list_array
{
 public:
	 list_array();
	 void add(DataType i);
	 void insert(DataType i);
	 int index(node<T> *_array);

	/* void Delete(DataType i);
	 void free_sll(node<T> *space, int k);
	 void xiu_gai(DataType i);*/

	 void disp();
	/* ~list_array();*/
 private:
	 DataType size;
	 node<T>Array[MAXSIZE];
};

template<class T>
list_array<T>::list_array()
{
	for (int i = 0; i < MAXSIZE-1; i++)
	{
		this->Array[i].cur = i + 1;
	}
	this->Array[MAXSIZE - 1].cur = 0;
	size = 0;
}

template<class T>
void list_array<T>::add(DataType i)
{
	T num;
	while (this->size < i)
	{
		cout << "请输入数字：";
		cin >> num;
		this->Array[size + 1].a = num;
		size++;
		if (size == i)
		{
			this->Array[MAXSIZE - 1].cur = 1;
			this->Array[0].cur = size + 1;
			this->Array[size].cur = 0;
		}
	}
}

template<class T>
void list_array<T>::insert(DataType i)
{
	int  k, j;
	k = MAXSIZE - 1;
	if (i<1 || i>size)
	{
		exit(0);
	}

	j = index(this->Array);
	if (j)
	{
		T num;
		cout << "输入字符：";
		cin >> num;
		this->Array[j].a = num;
		
		/*for (int n = 1; n < i - 1; n++)
		{
			k = this->Array[k].cur;
			this->Array[j].cur = this->Array[k].cur;
			this->Array[k].cur = j;
		}*/

		this->Array[j].cur = i + 1;
		this->Array[0].cur = j + 1;
		this->Array[i].cur = j;

		size++;
	}
}

template<class T>
int list_array<T>::index(node<T>*_array)
{ 
	int i = this->Array[0].cur;    //7


	if (this->Array[0].cur)    //7
	{
		this->Array[0].cur = this->Array[i].cur; 
	}
	return i;
}

//template<class T>
//void list_array<T>::Delete(DataType i)
//{
//	int k,j;
//	if (i<1 || i>size)
//	{
//		cout << "参数输入错误" << endl;
//	}
//
//	k = this->Array[MAXSIZE - 1].cur;
//	
//	size--;
//}
//
//template<class T>
//void list_array<T>::xiu_gai(DataType i)
//{
//	if (i<1 || i>size)
//	{
//		cout << "参数输入错误" << endl;
//	}
//
//	cout << "请输入你要修改的值：";
//	T num;
//	cin >> num;
//
//	for (int j = 0; j < size; i++)
//	{
//		if (this->Array[j].cur == i)
//		{
//			if (this->Array[i].a == "")
//			{
//				this->Array[i].a = num;
//				size++;
//				break;
//			}
//			this->Array[i].a = num;
//			break;
//		}
//		
//	}
//}
//
//template<class T>
//void list_array<T>::free_sll(node<T>*space, int k)
//{
//	space[k].cur = space[0].cur;
//	space[0].cur = k;
//}

template<class T>
void list_array<T>::disp()
{
	int i = this->Array[MAXSIZE-1].cur;  //1
	int length = 0;
	while (true)
	{
		cout << this->Array[i].a << " ";
		i = this->Array[i].cur;
		length++;
		if (length == size)
		{
			break;
		}
	}
}

int main()
{
	list_array<string>l;
	l.add(3);
	l.insert(2);
	l.disp();
	int num;

	/*cout << "你要删除第几个下标元素：";
	cin >> num;
	l.Delete(num);
	l.disp();
	l.xiu_gai(1);
	l.disp();*/

	return 0;
}