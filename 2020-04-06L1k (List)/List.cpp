#include "List.h"

void add(elem*& list, int data)
{
	elem* newel = new elem;
	newel->a = data;

	if (list)
	{
		//Добавляем элемент в конец списка
		elem* curr = list;
		while (curr->next!=nullptr)
		{
			curr = curr->next;
		}
		curr->next = newel;
	} else
	{
		list = newel;
	}
}

void insert(elem*& list, int data, int pos)
{
	elem* newel = new elem;
	newel->a = data;

	if (list && pos>0)
	{
		elem* curr = list;
		int p = 0;
		while (p<pos-1 && curr->next)
		{
			curr = curr->next;
			p++;
		}
		newel->next = curr->next;
		curr->next  = newel;
	} else
	{
		newel->next = list;
		list = newel;
	}
}

int* get(elem* list, int pos)
{
	if (pos < 0 || !list) return nullptr;
	int p = 0;
	elem* curr = list;
	while (curr && p < pos)
	{
		curr = curr->next;
		p++;
	}
	if (curr)
	{
		return &curr->a;
	}
	return nullptr;
}

int count(elem* list)
{
	int cnt = 0;
	elem* curr = list;
	while (curr)
	{
		cnt++;
		curr = curr->next;
	}
	return cnt;
}

bool remove(elem*& list, int pos)
{
	if (pos < 0 || !list) return false;
	if (pos==0)
	{
		elem* rem = list;
		list = list->next;
		delete rem;
		return true;
	}
	int p = 0;
	elem* curr = list;
	while (curr->next && p<pos-1)
	{
		curr = curr->next;
		p++;
	}
	if (p!=pos-1 || !curr->next)
	{
		return false;
	}
	elem* rem = curr->next;
	curr->next = curr->next->next;
	delete rem;
	return true;
}

void clear(elem*& list)
{
	while (list)
	{
		elem* rem = list;
		list = list->next;
		delete rem;
	}
}

