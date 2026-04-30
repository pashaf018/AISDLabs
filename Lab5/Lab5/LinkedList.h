#pragma once
#include "LinkedListNode.h"

class LinkedList
{
private:
	LinkedListNode* root = nullptr;
	LinkedListNode* end = nullptr;

	int Size = 0;
public:
	int* front();

	int* back();
	
	void push_front(int value);

	void push_back(int value);

	void pop_front();

	void pop_back();

	void insert(int index,int value);

	void erase(int index);

	int* element_at(int index);
};

