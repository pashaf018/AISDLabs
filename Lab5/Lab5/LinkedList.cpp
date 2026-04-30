#include "LinkedList.h"

void LinkedList::push_back(int value)
{
	LinkedListNode* newRoot = new LinkedListNode(value, root, nullptr);
	Size++;
	root = newRoot;
}

void LinkedList::push_front(int value)
{
	LinkedListNode* newEnd = new LinkedListNode(value, nullptr, end);
	Size++;
	end = newEnd;
}

void LinkedList::pop_front()
{
	if (root == nullptr)
	{
		return;
	}
	LinkedListNode* toDelete = root;
	root = root->Next;
	delete toDelete;
	Size--;
}

void LinkedList::pop_back()
{
	if (end == nullptr)
	{
		return;
	}
	LinkedListNode* toDelete = end;
	end = end->Previous;
	delete toDelete;
	Size--;
}

void LinkedList::insert(int index,int value)
{
	if (index < 0 || index >= Size)
	{
		return;
	}
	if (index == 0)
	{
		push_front(value);
		return;
	}
	if (index == Size - 1)
	{
		push_back(value);
		return;
	}

	LinkedListNode* ptr = root;
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->Next;
	}
	LinkedListNode* newEl = new LinkedListNode(value, ptr->Next, ptr);
	ptr->Next->Previous = newEl;
	ptr->Next = newEl;
	Size++;
}

void LinkedList::erase(int index)
{
	if (index < 0 || index >= Size)
	{
		return;
	}
	if (index == 0)
	{
		pop_front();
		return;
	}
	if (index == Size - 1)
	{
		pop_back();
		return;
	}

	LinkedListNode* ptr = root;
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->Next;
	}
	ptr->Previous->Next = ptr->Next;
	ptr->Next->Previous = ptr->Previous;
	delete ptr;
	Size--;
}

int* LinkedList::element_at(int index)
{
	if (index < 0 || index >= Size)
	{
		return nullptr;
	}

	LinkedListNode* ptr = root;
	for (int i = 0; i < index; i++)
	{
		ptr = ptr->Next;
	}
	return &ptr->Value;
}

int* LinkedList::front()
{
	if (root != nullptr)
	{
		return &root->Value;
	}
	return nullptr;
}

int* LinkedList::back()
{
	if (end != nullptr)
	{
		return &end->Value;
	}
	return nullptr;
}