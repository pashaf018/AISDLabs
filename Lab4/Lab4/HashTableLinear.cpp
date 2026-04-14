#include "HashTableLinear.h"

void HashTableLinear::insertValue(int i,int key, int value)
{
	HashTable[i].Key = key;
	HashTable[i].Value = value;
	HashTable[i].Removed = false;
	Elements++;
	if (((double) Elements / (double)Size) > 0.7)
	{
		reIndex(Size * 2);
	}
}

HashTableLinear::HashTableLinear(int size)
{
	if (size <= 0)
	{
		size = 1;
	}
	Size = size;
	HashTable = new HashElement[size];
	Elements = 0;
}

int HashTableLinear::getSize()
{
	return Size;
}

int* HashTableLinear::find(int* key)
{
	int hash = hashFunction(*key);
	for (int i = hash; i < Size; i++)
	{
		if (HashTable[i].Removed)
		{
			return nullptr;
		}
		if (HashTable[i].Key == *key)
		{
			return &HashTable[i].Value;
		}
	}
	for (int i = 0; i < hash && !HashTable[i].Removed; i++)
	{
		if (HashTable[i].Key == *key)
		{
			return &HashTable[i].Value;
		}
	}
	return nullptr;
}

int HashTableLinear::hashFunction(int key)
{
	return key % Size;
}

bool HashTableLinear::erase(int key) 
{
	// TODO
	return false;
}

void HashTableLinear::insert(int key, int value)
{
	int hash = hashFunction(key);
	for (int i = hash; i < Size; i++)
	{
		if (HashTable[i].Removed)
		{
			insertValue(i, key, value);
			return;
		}
	}
	for (int i = 0; i < hash; i++)
	{
		if (HashTable[i].Removed)
		{
			insertValue(i, key, value);
			return;
		}
	}
}

bool HashTableLinear::reIndex(int newSize)
{
	if (newSize <= 0)
	{
		return false;
	}
	HashElement* newTable = new HashElement[newSize];
	int j = 0;
	int temp = Size;
	Size = newSize;
	HashElement* toDelete = HashTable;
	HashTable = newTable;
	for (int i = 0; i < temp && j < Elements; i++)
	{
		if (!toDelete[i].Removed)
		{
			Elements--;
			insert(toDelete[i].Key, toDelete[i].Value);
			j++;
		}
	}
	delete[] toDelete;
	return true;
}

std::string HashTableLinear::toString()
{
	std::string res = "";
	if (Size <= 0)
	{
		return res;
	}
	for (int i = 0; i < Size; i++)
	{
		res += "[";
		if (!HashTable[i].Removed)
		{
			res += std::to_string(HashTable[i].Key) + ", " + std::to_string(HashTable[i].Value);
		}
		res += "] ";
	}
	return res;
}