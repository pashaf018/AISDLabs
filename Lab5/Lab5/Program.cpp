#include "Includes.h"
#include "HashTableChains.h"

void main()
{
	const int N = 100000;
	std::unordered_map<int, int> table;

	// вставка
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		table[i] = rand() % 100000;
	}

	auto end = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long double> duration = end - start;
	size_t memory = sizeof(table) + (table.size() * sizeof(typename std::unordered_map<int,int>::value_type) + (table.size() * sizeof(void*)) + table.bucket_count() * sizeof(void*));


	// поиск
	auto start1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		int value = table[i];
	}

	auto end1 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long double> duration1 = end1 - start1;


	// удаление
	auto start2 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		table.erase(i);
	}

	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration2 = end2 - start2;

	// Моя реализация
	HashTableChains hashTable = HashTableChains(1);

	// вставка
	auto start3 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		hashTable.insert(i,rand() % 100000);
	}

	auto end3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration3 = end3 - start3;
	int memory1 = hashTable.getMemory();

	// поиск
	auto start4 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		int* value = hashTable.search(i);
	}

	auto end4 = std::chrono::high_resolution_clock::now();

	std::chrono::duration<long double> duration4 = end4 - start4;

	// удаление
	auto start5 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		hashTable.erase(i);
	}

	auto end5 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration5 = end5 - start5;


	std::cout << "\tStructure\tN\tCustom(ms)\tStandart(ms)\tC_memory\tS_memory" << std::endl;
	std::cout << std::fixed << std::setprecision(8) << "hashTable.insert() |\t" << N << " |\t" << duration3.count() << " |\t" << duration.count() << " |\t" << memory1 << " |\t" << memory << " |\t" << std::endl;
	std::cout << "hashTable.search() |\t" << N << " |\t" << duration4.count() << " | \t" << duration1.count() << " | \t" << std::endl;
	std::cout << "hashTable.erase()  |\t" << N << " |\t" << duration5.count() << " |\t" << duration2.count() << " |\t" << std::endl;
}