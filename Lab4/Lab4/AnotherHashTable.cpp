#include "AnotherHashTable.h"

AnotherHashTable::AnotherHashTable(int size)
{
	if (size <= 0)
	{
		size = 1;
	}
	Size = size;
	HashTable = std::vector<std::pair<int, int>*>(size,nullptr);
	Elements = 0;
}

bool AnotherHashTable::checkBloomFilter(int key)
{
	return bloomFilter.checkBloom(hashFunction1(key), hashFunction2(key), hashFunction3(key));
}

int AnotherHashTable::getSize()
{
	return Size;
}

int* AnotherHashTable::find(int key)
{
	if (!checkBloomFilter(key))
	{
		return nullptr;
	}
	int hash1 = hashFunction1(key);
	int hash2 = hashFunction2(key);
	int hash3 = hashFunction3(key);
	if (HashTable[hash1] != nullptr && HashTable[hash1]->first == key)
	{
		return &HashTable[hash1]->second;
	}
	if (HashTable[hash2] != nullptr && HashTable[hash2]->first == key)
	{
		return &HashTable[hash2]->second;
	}
	if (HashTable[hash3] != nullptr && HashTable[hash3]->first == key)
	{
		return &HashTable[hash3]->second;
	}
	return nullptr;
}

int AnotherHashTable::hashFunction1(int key)
{
	std::cout << "Хэш-функция 1: " << std::to_string((key * 123) % Size) << std::endl;
	return (key * 123) % Size;
}

int AnotherHashTable::hashFunction2(int key)
{
	std::cout << "Хэш-функция 2: " << std::to_string((int)(key * 11.6) % Size) << std::endl;
	return (int)(key * 11.6) % Size;
}

int AnotherHashTable::hashFunction3(int key)
{
	std::cout << "Хэш-функция 3: " << std::to_string((int)(key * 9.3) % Size) << std::endl;
	return (int)(key * 9.3) % Size;
}

bool AnotherHashTable::erase(int key)
{
	if (HashTable[hashFunction1(key)] != nullptr)
	{
		delete HashTable[hashFunction1(key)];
		HashTable[hashFunction1(key)] = nullptr;
		Elements--;
		return true;
	}
	if (HashTable[hashFunction2(key)] != nullptr)
	{
		delete HashTable[hashFunction2(key)];
		HashTable[hashFunction2(key)] = nullptr;
		Elements--;
		return true;
	}
	if (HashTable[hashFunction3(key)] != nullptr)
	{
		delete HashTable[hashFunction3(key)];
		HashTable[hashFunction3(key)] = nullptr;
		Elements--;
		return true;
	}
	return false;
}

void AnotherHashTable::insert(int key, int value)
{
	std::cout << "Поиск места для числа: " << std::to_string(key) << std::endl;
	int hash1 = hashFunction1(key);
	int hash2 = hashFunction2(key);
	int hash3 = hashFunction3(key);

	if (HashTable[hash1] == nullptr)
	{
		HashTable[hash1] = new std::pair<int, int>(key, value);
		Elements++;
		bloomFilter.fillBloom(hash1, hash2, hash3);
	}
	else if (HashTable[hash2] == nullptr)
	{
		HashTable[hash2] = new std::pair<int, int>(key, value);
		Elements++;
		bloomFilter.fillBloom(hash1, hash2, hash3);
	}
	else if (HashTable[hash2] == nullptr)
	{
		HashTable[hash2] = new std::pair<int, int>(key, value);
		Elements++;
		bloomFilter.fillBloom(hash1, hash2, hash3);
	}

	if (((double)Elements / (double)Size) > 0.7)
	{
		reIndex(Size * 2);
	}
}

bool AnotherHashTable::reIndex(int newSize)
{
	if (newSize <= 0)
	{
		return false;
	}
	int temp = Size;
	Size = newSize;
	std::vector<std::pair<int, int>*> toDelete = HashTable;
	HashTable = std::vector<std::pair<int, int>*>(Size, nullptr);
	bloomFilter.clearFilter();
	for (int i = 0; i < temp; i++)
	{
		std::pair<int, int>* pair = toDelete[i];
		if (pair == nullptr)
		{
			continue;
		}
		Elements--;
		insert(pair->first, pair->second);
	}
	toDelete.clear();
	return true;
}

void AnotherHashTable::toString()
{
	for (int i = 0; i < Size; i++)
	{
		std::cout << "[ ";
		if (HashTable[i] != nullptr)
		{
			std::cout << "(" << std::to_string(HashTable[i]->first) << " : " << std::to_string(HashTable[i]->second) << ")";
		}
		std::cout << " ] ";
	}
	std::cout << std::endl;
}

void AnotherHashTable::printBloomFilter()
{
	bloomFilter.printBloomFilter();
}