#pragma once

struct elem
{
	int a;
	elem* next = nullptr;
};

void add(elem*& list, int data);

void insert(elem*& list, int data, int position);

int* get(elem* list, int position);

int count(elem* list);

bool remove(elem*& list, int position);

void clear(elem*& list);