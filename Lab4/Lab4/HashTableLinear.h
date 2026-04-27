#pragma once
#include "HashElement.h"
#include "Includes.h"

class HashTableLinear
{
private:
	HashElement* HashTable;

	int Size;

	int Elements;

	void insertValue(int,int, int);
public:
	HashTableLinear(int);

	int getSize();

	int* find(int);

	int hashFunction(int);

	bool erase(int);

	void insert(int, int);

	bool reIndex(int);

	std::string toString();
};

