#include "Includes.h"
#include "HashTableChains.h"
#include "MergeSort.h"
#include "BubbleSort.h"
#include "Stack.h"
#include "LinkedList.h"

int compare(const void* a, const void* b)
{
	int A = *(const int*)a;
	int B = *(const int*)b;
	return (A > B) - (A < B);
}

void main()
{
	//const int N = 100000;
	//std::unordered_map<int, int> table;

	//// вставка
	//auto start = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	table[i] = rand() % 100000;
	//}

	//auto end = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration = end - start;
	//size_t memory = sizeof(table) + (table.size() * sizeof(typename std::unordered_map<int,int>::value_type) + (table.size() * sizeof(void*)) + table.bucket_count() * sizeof(void*));


	//// поиск
	//auto start1 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	int value = table[i];
	//}

	//auto end1 = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration1 = end1 - start1;


	//// удаление
	//auto start2 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	table.erase(i);
	//}

	//auto end2 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration2 = end2 - start2;

	//// Моя реализация
	//HashTableChains hashTable = HashTableChains(1);

	//// вставка
	//auto start3 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	hashTable.insert(i,rand() % 100000);
	//}

	//auto end3 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration3 = end3 - start3;
	//int memory1 = hashTable.getMemory();

	//// поиск
	//auto start4 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	int* value = hashTable.search(i);
	//}

	//auto end4 = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration4 = end4 - start4;

	//// удаление
	//auto start5 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	hashTable.erase(i);
	//}

	//auto end5 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration5 = end5 - start5;


	//std::cout << "\tStructure\tN\tCustom(ms)\tStandart(ms)\tC_memory\tS_memory" << std::endl;
	//std::cout << std::fixed << std::setprecision(8) << "hashTable.insert() |\t" << N << " |\t" << duration3.count() << " |\t" << duration.count() << " |\t" << memory1 << " |\t" << memory << " |\t" << std::endl;
	//std::cout << "hashTable.search() |\t" << N << " |\t" << duration4.count() << " | \t" << duration1.count() << " | \t" << std::endl;
	//std::cout << "hashTable.erase()  |\t" << N << " |\t" << duration5.count() << " |\t" << duration2.count() << " |\t" << std::endl;



	//binary search tree

	//const int N = 100000;

	//std::map<int,int> BST;
	//int memory = 0;

	////вставка

	//auto start = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	BST.insert(std::pair<int, int>(i, rand() % 100000));
	//	memory += sizeof(i) + sizeof(int) + 3 * sizeof(void*);
	//}

	////memory += sizeof(BST.begin());

	//auto end = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration = end - start;

	////поиск

	//auto start1 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	auto it = BST.find(i);
	//}

	//auto end1 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration1 = end1 - start1;

	////удаление

	//auto start2 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	BST.erase(i);
	//}

	//auto end2 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration2 = end2 - start2;

	////моя реализация

	//BinarySearchTree* MyBST = nullptr;
	//int memory1 = 0;

	////вставка

	//auto start3 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	MyBST->insert(MyBST, i, rand() % 100000);
	//	memory1 += sizeof(BinarySearchTree*);
	//}

	//auto end3 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration3 = end3 - start3;

	////поиск

	//auto start4 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	BinarySearchTree* val = MyBST->search(MyBST, i);
	//}

	//auto end4 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration4 = end4 - start4;

	////удаление

	//auto start5 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	MyBST->erase(MyBST, i);
	//}

	//auto end5 = std::chrono::high_resolution_clock::now();
	//std::chrono::duration<long double> duration5 = end5 - start5;

	//std::cout << "\tStructure\tN\tCustom(ms)\tStandart(ms)\tC_memory\tS_memory" << std::endl;
	//std::cout << std::fixed << std::setprecision(8) << "BST.insert() |\t" << N << " |\t" << duration3.count() << " |\t" << duration.count() << " |\t" << memory1 << " |\t" << memory << " |\t" << std::endl;
	//std::cout << "BST.search() |\t" << N << " |\t" << duration4.count() << " | \t" << duration1.count() << " | \t" << std::endl;
	//std::cout << "BST.erase()  |\t" << N << " |\t" << duration5.count() << " |\t" << duration2.count() << " |\t" << std::endl;


	//Stack

	//const int N = 1000000;
	//std::stack<int> standart;


	////вставка
	//auto start = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	standart.push(rand() % 100000);
	//}

	//auto end = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration = end - start;

	////pop + top
	//auto start1 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	int value = standart.top();
	//	standart.pop();
	//}

	//auto end1 = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration1 = end1 - start1;


	////Моя
	//
	//Stack stack;

	////push
	//auto start2 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	stack.push(rand() % 100000);
	//}

	//auto end2 = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration2 = end2 - start2;

	////pop + top
	//auto start3 = std::chrono::high_resolution_clock::now();

	//for (int i = 0; i < N; i++)
	//{
	//	int value = stack.top();
	//	stack.pop();
	//}

	//auto end3 = std::chrono::high_resolution_clock::now();

	//std::chrono::duration<long double> duration3 = end3 - start3;


	//std::cout << "\tStructure\tN\tCustom(ms)\tStandart(ms)\tC_memory\tS_memory" << std::endl;
	//std::cout << std::fixed << std::setprecision(8) << "Stack.push() |\t" << N << " |\t" << duration2.count() << " |\t" << duration.count() << " |\t" << std::endl;
	//std::cout << "Stack.top().pop() |\t" << N << " |\t" << duration3.count() << " | \t" << duration1.count() << " | \t" << std::endl;


	//LinkedList
	
	const int N = 100000;

	std::list<int> listS;


	//push_back
	auto start = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		listS.push_back(rand() % 10000);
	}

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration = end - start;

	//front + pop_front
	auto start1 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		int value = listS.front();
		listS.pop_front();
	}

	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration1 = end1 - start1;

	LinkedList MyList;

	//push
	auto start2 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		MyList.push_back(rand() % 10000);
	}

	auto end2 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration2 = end2 - start2;

	//front + pop_front()
	auto start3 = std::chrono::high_resolution_clock::now();

	for (int i = 0; i < N; i++)
	{
		int* value = MyList.front();
		MyList.pop_front();
	}

	auto end3 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration3 = end3 - start3;

	std::cout << "\tStructure\tN\tCustom(ms)\tStandart(ms)\tC_memory\tS_memory" << std::endl;
	std::cout << std::fixed << std::setprecision(8) << "List.push() |\t" << N << " |\t" << duration2.count() << " |\t" << duration.count() << " |\t" << std::endl;
	std::cout << "List.front().pop() |\t" << N << " |\t" << duration3.count() << " | \t" << duration1.count() << " | \t" << std::endl;
}