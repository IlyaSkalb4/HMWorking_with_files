#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	fstream file;
	string strfile, buf, begin, end;
	bool logik;
	char symbol = '.';
	int pos = 0;
	file.open("file.txt", ios::in);
	if (!file.is_open())
	{
		cout << "Not found" << endl;
	}
	else
	{
		while (getline(file, strfile))
		{
			buf += strfile;
			buf += "\n";
		}
		strfile.clear();
		file.close();
		do
		{
			pos = buf.find(symbol);
			logik = true;
			if (pos == -1)
			{
				break;
			}
			else
			{
				for (int i = 0; i < buf.length(); i++)
				{
					if (i <= pos)
					{
						begin += buf[i];
						if (islower(buf[i])&&logik)
						{
							begin[i] = toupper(begin[i]);
							logik = false;
						}
					}
					else if (i > pos)
					{
						end += buf[i];

					}
				}
				strfile += begin;
				buf = end;
				begin.clear();
				end.clear();
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