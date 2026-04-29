#include "Includes.h";
#include "HashTableLinear.h"
#include "HashTableChains.h"
#include "AnotherHashTable.h"

void main()
{
	setlocale(LC_ALL, "Russian");

	/*HashTableLinear hashTable = HashTableLinear(10);
	hashTable.insert(5, 500);
	std::string res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(6, 300);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(15, 400);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(9, 4123);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(7, 500);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(6, 300);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(15, 400);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(29, 4123); 
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.erase(15);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.erase(7);
	res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.erase(9);

	int value = 15;
	int* finding = hashTable.find(value);
	std::string res = hashTable.toString();
	std::cout << res + "\nНайденное число: " << *finding;*/
	

	/*HashTableChains hashTable = HashTableChains(4);
	hashTable.insert(500);
	hashTable.erase(500);
	hashTable.insert(500);
	hashTable.insert(500);
	hashTable.insert(500);
	hashTable.insert(100);
	hashTable.insert(10);
	hashTable.insert(3);
	hashTable.printString();*/


	AnotherHashTable hashTable = AnotherHashTable(4);
	hashTable.insert(10, 500);
	hashTable.toString();
	hashTable.printBloomFilter();
	hashTable.insert(15, 431);
	hashTable.toString();
	hashTable.printBloomFilter();
	hashTable.insert(5, 123);
	hashTable.toString();
	hashTable.printBloomFilter();
	std::cout << hashTable.checkBloomFilter(123) << std::endl;
	std::cout << hashTable.checkBloomFilter(5) << std::endl;
	hashTable.insert(62, 512621500);
	hashTable.toString();
	hashTable.printBloomFilter();
	hashTable.insert(321, 1231);
	hashTable.toString();
	hashTable.printBloomFilter();
	std::cout << hashTable.checkBloomFilter(18) << std::endl;
	hashTable.insert(1256, 1241);
	hashTable.toString();
	hashTable.printBloomFilter();
	hashTable.insert(123, 1242156);
	hashTable.toString();
	hashTable.printBloomFilter();
}