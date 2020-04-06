#include <iostream>
#include <Windows.h>
#include <fstream>
#include "List.h"
using namespace std;

void fillList(elem*& list)
{
	ifstream f("data.txt");
	if (f.is_open())
	{
		char* data = new char[31];
		while (!f.eof())
		{
			f.getline(data, 31, '\n');
			if (f.fail())
			{
				break;
			}
			int v, p;
			int cnt = sscanf_s(data, "%d %d", &v, &p);
			switch (cnt)
			{
			case 1:
				{
					add(list, v);
					break;
				}
			case 2:
				{
					insert(list, v, p);
				}
			}
		}
		f.close();
	}
}

void showList(elem* list)
{
	elem* curr = list;
	if (!curr) cout << "EMPTY LIST" << endl;
	while (curr)
	{
		cout << curr->a << (curr->next?" ":"\n");
		curr = curr->next;
	}
}

void showOdd(elem* list)
{
	int cnt = count(list);
	for (int i = 1; i<cnt; i+=2)
	{
		auto val = get(list, i);
		cout << *val << ((i+2<cnt)?" ":"\n");
	}
}

void main()
{
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	elem* list1 = nullptr;
	fillList(list1);
	showList(list1);//300 -10 -1 30 1 10 100 200
	showOdd(list1); //-10 30 10 200
	remove(list1, 0);
	showList(list1);//-10 -1 30 1 10 100 200
	remove(list1, 1);
	showList(list1);//-10 30 1 10 100 200
	remove(list1, 100);
	showList(list1);//-10 30 1 10 100 200
	remove(list1, -10);
	showList(list1);//-10 30 1 10 100 200
	clear(list1);
	system("pause");
}