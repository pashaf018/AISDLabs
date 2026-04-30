#include "Stack.h"

void Stack::push(int value)
{
	root = root->push(root, value);
}

int Stack::top()
{
	return root->Value;
}

void Stack::pop()
{
	root = root->pop(root);
}