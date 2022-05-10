#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream file;
	ofstream file2;
	string strfile, strABC="abcdefghijklmnopqrstuvwxyz";
	char symbol;
	int length = 0, lengthArr = strABC.length();
	int* countarray = new int[lengthArr];
	for (int i = 0; i < lengthArr; i++)
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
				symbol = strfile[i];
				if (!islower(symbol))
				{
					symbol = tolower(symbol);
				}
				for (int j = 0; j < lengthArr; j++)
				{
					if (symbol == strABC[j])
					{
						countarray[j] += 1;
					}
				}
			}
		}
		for (int i = 0; i < lengthArr; i++)
		{
			file2 << "Number of letter '" << strABC[i] << "' = " << countarray[i] << endl;
		}
	}
	file2.close();
	file.close();
	delete[] countarray;
	return 0;
}