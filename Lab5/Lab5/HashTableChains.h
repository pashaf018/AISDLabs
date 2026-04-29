#pragma once
#include "BinarySearchTree.h"
#include "Includes.h"

class HashTableChains
{
private:
	std::vector<BinarySearchTree*> HashTable;

	int Size;

	int Count;

	std::vector<int> MemoryUsage;
public:
	HashTableChains(int);

	int hashFunction(int);

	bool reIndex(int);

	void insert(int, int);

	int* search(int);

	bool erase(int);

	int getSize();

	void printString();

	int getMemory();
};