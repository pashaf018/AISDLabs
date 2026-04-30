#include "StackList.h"

StackList* StackList::push(StackList* root,int value)
{
	StackList* newRoot = new StackList(value, root);
	return newRoot;
}

int StackList::top(StackList* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return root->Value;
}

StackList* StackList::pop(StackList* root)
{
	if (root == nullptr)
	{
		return root;
	}
	StackList* newRoot = root->Next;
	delete root;
	return newRoot;
}