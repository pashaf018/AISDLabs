#pragma once
#include "Includes.h"
#include "BloomFilter.h"
#include "HashElement.h"

class AnotherHashTable
{
private:
	std::vector<std::pair<int,int>*> HashTable;

	int Size;

	int Elements;

	BloomFilter bloomFilter = BloomFilter(10);
public:
	AnotherHashTable(int);

	bool checkBloomFilter(int);

	int getSize();

	int* find(int);

	int hashFunction1(int);

	int hashFunction2(int);

	int hashFunction3(int);

	bool erase(int);

	void insert(int, int);

	bool reIndex(int);

	void toString();

	void printBloomFilter();
};

