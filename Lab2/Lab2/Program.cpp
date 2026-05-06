#include "OrdersTest.h"
#include "FibonacciTest.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "Tree.h"
#include "SelectSort.h"

std::list<int>::iterator FindEl(std::list<int>& arr, int i)
{
	int j = 0;
	for (std::list<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		if (j == i)
		{
			return it;
		}
		j++;
	}
	return arr.begin();
}

void InsertSort(std::list<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::list<int>::iterator Eli = FindEl(arr, i);
		std::list<int>::iterator ElMin = Eli;
		for (int j = i + 1; j < arr.size(); j++)
		{
			std::list<int>::iterator Elj = FindEl(arr, j);
			int first = *ElMin;
			int second = *Elj;
			if (first > second)
			{
				ElMin = Elj;
			}
		}
		arr.splice(Eli, arr, ElMin);
	}
}

void quickSort(std::list<int>& arr)
{

}

void PrintList(std::list<int> arr)
{
	std::cout << "\nList:\n";
	for (std::list<int>::iterator it = arr.begin(); it != arr.end(); it++)
	{
		std::cout << "[" << *it << "] ";
	}
	std::cout << std::endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	const int N = 10;
	std::list<int> arr;
	for (int i = 0; i < N; i++)
	{
		arr.push_back(rand() % 100000);
	}
	PrintList(arr);
	InsertSort(arr);
	PrintList(arr);

	/*std::vector<int> arr = generateRandomArray(10);
	printArray(arr);
	SelectSort::selectSort(arr);
	printArray(arr);
	std::cout << "Среднее время выполнения сортировки выбором: " << SelectSort::testAlgorithm(100);*/

	/*std::vector<Order> orders = OrdersTest::generateRandom(10, 100);
	OrdersTest::printOrders(orders);
	orders = OrdersTest::sortOrders(orders);
	OrdersTest::printOrders(orders);
	Orders solved = OrdersTest::OrdersAlgorithm(orders);
	OrdersTest::printOrders(solved.getOrders());
	std::cout << "Среднее время выполнения алгоритма с заявками: " << OrdersTest::testAlgorithm(100);*/

	/*std::vector<int> arr = generateRandomArray(10);
	printArray(arr);
	bubbleSort(&arr);
	printArray(arr);
	std::cout << "Среднее время сортировки пузырьком: " << testBubbleSort(100);*/

	/*std::vector<int> arr = generateRandomArray(10);
	printArray(arr);
	MergeSort::mergeSort(arr,0, 9);
	printArray(arr);
	std::cout << "Среднее время сортировки слиянием: " << MergeSort::testMergeSorting(100);*/


	/*TreeNode* node = new TreeNode(500);
	node->right = nullptr;
	node->left = nullptr;
	Tree tree = Tree();
	std::cout << "Среднее время поиска в двоичном дереве: " << tree.testBinarySearch(10);
	std::cout << "\nСреднее время поиска в массиве: " << Tree::testArray(10);*/

	//FibonacciTest fibonacci;
	//std::cout << "Среднее время работы алгоритма Фибоначчи: " << fibonacci.testAlgorithm(100) << "\n\n";
	//std::cout << "Время работы алгоритма Фибоначчи без сохранений: " << fibonacci.findFibonacciStraight(50) << "\n\n";
}