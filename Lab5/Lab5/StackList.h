#pragma once
struct StackList
{
	int Value;
	StackList* Next;
	StackList(int value,StackList* old) : Value(value), Next(old) {}

	StackList* push(StackList*, int);

	int top(StackList*);

	StackList* pop(StackList*);
};

