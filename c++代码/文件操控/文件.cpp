#include<iostream>
using namespace std;
#include<fstream>

int main()
{
	/*ofstream ofs;
	ofs.open("myfile.txt", ios::out);
	ofs << "这是第一份文件";
	ofs.close();*/

	ifstream ifs;
	ifs.open("myfile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败" << endl;
		exit(0);
	}

	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	return 0;
}