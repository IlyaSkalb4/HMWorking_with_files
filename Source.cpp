#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	ofstream file2;
	string strfile;
	int length = 0, number = 0, lengthNum = 10;
	int* countarray = new int[lengthNum];
	for (int i = 0; i < lengthNum; i++)
	{
		countarray[i] = 0;
	}
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
			length = strfile.length();
			for (int i = 0; i < length; i++)
			{
				if (isdigit(strfile[i]) != 0)
				{
					number = strfile[i] - '0';
				}
				for (int j = 0; j < lengthNum; j++)
				{
					if (number == j)
					{
						countarray[j] += 1;
					}
				}
			}
		}
		number = 0;
		for (int i = 0; i < lengthNum; i++)
		{
			file2 << "Number of digits '" << i << "' = " << countarray[i] << endl;
			number += countarray[i];
		}
		file2 << "Total digits: " << number;
	}
	file2.close();
	file.close();
	delete[] countarray;
	return 0;
}