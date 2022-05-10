#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	string strfile, givenword, word;
	fstream file;
	file.open("file.txt", ios::in);
	cout << "Enter word: ";
	cin >> givenword;
	cout << "Enter word: ";
	cin >> word;
	if (!file.is_open())
	{
		cout << "Not found" << endl;
	}
	else
	{
		string buf, begin, end;
		while (getline(file, buf))
		{
			strfile += buf;
			strfile += "\n";
		}
		file.close();
		int pos;
		cout << strfile << endl;
		
		do
		{
			buf.clear();
			pos = strfile.find(givenword);
			if (pos == -1)
			{
				break;
			}
			else
			{
				
				for (size_t i = 0; i < strfile.length(); i++)
				{
					if (i < pos)
					{
						begin+=strfile[i];
					}
					else if (i >= pos + givenword.size())
					{
						end+=strfile[i];
					}
				}
				buf = begin + word + end;
				strfile = buf;
				begin.clear();
				end.clear();
				cout << buf << endl;
			}
		} while (true);
		file.open("file.txt", ios::out | ios::ate);
		if (!file.is_open())
		{
			cout << "Not found" << endl;
		}
		else
		{
			file << strfile << endl;
			file.close();
		}
	}
	return 0;
}