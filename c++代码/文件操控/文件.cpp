#include<iostream>
using namespace std;
#include<fstream>

int main()
{
	/*ofstream ofs;
	ofs.open("myfile.txt", ios::out);
	ofs << "���ǵ�һ���ļ�";
	ofs.close();*/

	ifstream ifs;
	ifs.open("myfile.txt", ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ��" << endl;
		exit(0);
	}

	char buf[1024] = { 0 };
	while (ifs.getline(buf, sizeof(buf)))
	{
		cout << buf << endl;
	}

	return 0;
}