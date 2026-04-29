#pragma once
#include "Includes.h"

class BloomFilter
{
private:
	std::vector<bool> bloomArray;

public:
	BloomFilter(int);

	int hashFunction(int);

	bool checkBloom(int, int, int);

	void fillBloom(int, int, int);

	void printBloomFilter();

	void clearFilter();
};