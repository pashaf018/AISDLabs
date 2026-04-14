#include "Includes.h";
#include "HashTableLinear.h"
#include <iostream>

void main()
{
	setlocale(LC_ALL, "Russian");

	HashTableLinear hashTable = HashTableLinear(10);
	hashTable.insert(5, 500);
	hashTable.insert(6, 300);
	hashTable.insert(15, 400);
	hashTable.insert(9, 4123);
	hashTable.insert(7, 500);
	std::string res1 = hashTable.toString();
	std::cout << res1 << std::endl;
	hashTable.insert(6, 300);
	hashTable.insert(15, 400);
	hashTable.insert(9, 4123);
	int value = 15;
	int* finding = hashTable.find(&value);
	std::string res = hashTable.toString();
	std::cout << res + "\nНайденное число: " << *finding;
}