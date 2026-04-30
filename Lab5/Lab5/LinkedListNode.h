#pragma once
struct LinkedListNode
{
	int Value;
	LinkedListNode* Next;
	LinkedListNode* Previous;
	LinkedListNode(int value,LinkedListNode* next, LinkedListNode* prev) : Value(value),Next(next),Previous(prev){}
};

