#include "HashTableChains.h"

HashTableChains::HashTableChains(int size)
{
	if (size <= 0)
	{
		size = 1;
	}
	Size = size;
	HashTable = std::vector<BinarySearchTree*>(Size,nullptr);
	Count = 0;
}

int HashTableChains::hashFunction(int key) { return key % Size; }

bool HashTableChains::reIndex(int newSize)
{
	if (newSize <= 0)
	{
		return false;
	}
	
	std::vector<BinarySearchTree*> temp = HashTable;
	Size = newSize;
	HashTable = std::vector<BinarySearchTree*>(newSize,nullptr);
	for (int i = 0; i < Count; i++)
	{
		while (true)
		{
			BinarySearchTree* p = temp[i]->findMin(temp[i]);
			if (p == nullptr)
			{
				break;
			}
			Count--;
			insert(p->Value);
			temp[i] = temp[i]->erase(temp[i], p->Value);
		}
	}
	temp.clear();
	return true;
}

void HashTableChains::insert(int value)
{
	int hash = hashFunction(abs(value));
	HashTable[hash] = HashTable[hash]->insert(HashTable[hash], value);
	Count++;
	if (((double)Count / (double)Size) > 0.7)
	{
		reIndex(Size * 2);
	}
}

bool HashTableChains::erase(int value)
{
	int hash = hashFunction(abs(value));
	BinarySearchTree* deleting = HashTable[hash]->search(HashTable[hash], value);
	if (deleting == nullptr)
	{
		return false;
	}
	HashTable[hash] = HashTable[hash]->erase(HashTable[hash], value);
	Count--;
	return true;
}

int HashTableChains::getSize() { return Size; }

void HashTableChains::printString()
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "[ ";
		HashTable[i]->toString(HashTable[i]);
		std::cout << " ] ";
	}
}
