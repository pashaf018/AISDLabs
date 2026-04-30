#pragma once
#include "StackList.h"

class Stack
{
private:
	StackList* root = nullptr;
public:
	void push(int);

	int top();

	void pop();
};

