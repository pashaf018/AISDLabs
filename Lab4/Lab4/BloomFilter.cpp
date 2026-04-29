#include "BloomFilter.h"

BloomFilter::BloomFilter(int size)
{
	if (size > 0)
	{
		size = 10;
	}
	bloomArray = std::vector<bool>(size, false);
}

int BloomFilter::hashFunction(int key)
{
	std::cout << "Рассматриваемый бит: " << key % bloomArray.size() << std::endl;
	return key % bloomArray.size();
}

bool BloomFilter::checkBloom(int hash1, int hash2, int hash3)
{
	if (bloomArray[hashFunction(hash1)] && bloomArray[hashFunction(hash2)] && bloomArray[hashFunction(hash3)])
	{
		return true;
	}
	return false;
}

void BloomFilter::fillBloom(int hash1, int hash2, int hash3)
{
	bloomArray[hashFunction(hash1)] = true;
	bloomArray[hashFunction(hash2)] = true;
	bloomArray[hashFunction(hash3)] = true;
}

void BloomFilter::printBloomFilter()
{
	for (int i = 0; i < bloomArray.size(); i++)
	{
		std::cout << "[ " << (bloomArray[i] ? "1" : "0") << " ]";
	}
	std::cout << std::endl;
}

void BloomFilter::clearFilter()
{
	bloomArray.clear();
	bloomArray = std::vector<bool>(10, false);
}