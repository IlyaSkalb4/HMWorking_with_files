#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string strfile,replaceWord, replacementWord;
	ifstream file("file.txt",ios::in);
	cout << "Enter replacement word: ";
	cin >> replacementWord;
	cout << "Replace the word with: ";
	cin >> replaceWord;
	if (!file.is_open())
	{
		cout << "Invalid" << endl;
	}
	else
	{
		while (getline(file, strfile))
		{
			
		}
	}
	return 0;
}