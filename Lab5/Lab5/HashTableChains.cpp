#include "HashTableChains.h"

HashTableChains::HashTableChains(int size)
{
	if (size <= 0)
	{
		size = 1;
	}
	Size = size;
	HashTable = std::vector<BinarySearchTree*>(Size, nullptr);
	MemoryUsage = std::vector<int>(Size, 0);
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
	MemoryUsage.clear();
	Size = newSize;
	MemoryUsage = std::vector<int>(Size,0);
	HashTable = std::vector<BinarySearchTree*>(newSize, nullptr);
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
			insert(p->Key,p->Value);
			temp[i] = temp[i]->erase(temp[i], p->Key);
		}
	}
	temp.clear();
	return true;
}

void HashTableChains::insert(int key, int value)
{
	int hash = hashFunction(abs(key));
	HashTable[hash] = HashTable[hash]->insert(HashTable[hash], key, value);
	MemoryUsage[hash] += sizeof(BinarySearchTree);
	Count++;
	if (((double)Count / (double)Size) > 0.7)
	{
		reIndex(Size * 2);
	}
}

bool HashTableChains::erase(int key)
{
	int hash = hashFunction(abs(key));
	BinarySearchTree* deleting = HashTable[hash]->search(HashTable[hash], key);
	if (deleting == nullptr)
	{
		return false;
	}
	HashTable[hash] = HashTable[hash]->erase(HashTable[hash], key);
	Count--;
	MemoryUsage[hash] -= sizeof(BinarySearchTree);
	return true;
}

int* HashTableChains::search(int key)
{
	int hash = hashFunction(abs(key));
	BinarySearchTree* found = HashTable[hash]->search(HashTable[hash],key);
	if (found == nullptr)
	{
		return nullptr;
	}
	return &found->Value;
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

int HashTableChains::getMemory()
{
	int result = 0;
	for (int i = 0; i < Size; i++)
	{
		result += MemoryUsage[i];
	}
	return result + sizeof(Size) + sizeof(Count) + sizeof(HashTable.capacity() * sizeof(BinarySearchTree*));
}
