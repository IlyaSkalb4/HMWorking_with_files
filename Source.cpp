#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	ofstream file2;
	string strfile, strfile2;
	int countr = 0, length = 0;
	file.open("file.txt", ios::in);
	file2.open("file2.txt", ios::out);
	if (!file.is_open())
	{
		cout << "Not found";
	}
	else
	{
		while (getline(file, strfile))
		{
			char* pch = strtok((char*)strfile.c_str(), ".");
			while (pch != NULL)
			{
				if (islower(pch[0]))
				{
					pch[0] = toupper(pch[0]);
				}
				file2 << pch << ".";
				pch = strtok(NULL, ".");
			}
			file2 << endl;
		}
	}
	return 0;
}