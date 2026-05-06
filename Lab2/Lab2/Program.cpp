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
			if (*ElMin > *Elj)
			{
				ElMin = Elj;
			}
		}
		arr.splice(Eli, arr, ElMin);
	}
}

void InsertSortArray(int* arr,int size)
{
	for (int i = 0; i < size; i++)
	{
		int minI = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[minI] > arr[j])
			{
				minI = j;
			}
		}
		int temp = arr[minI];
		arr[minI] = arr[i];
		arr[i] = temp;
	}
}

int partition(std::list<int>& arr, int low, int high)
{
	std::list<int>::iterator pivot = FindEl(arr,low);
	int i = low;
	int j = high;

	while (i < j)
	{
		while (*FindEl(arr,i) <= *pivot && i <= high - 1)
		{
			i++;
		}
		while (*FindEl(arr,j) > *pivot && j >= low + 1)
		{
			j--;
		}
		if (i < j)
		{
			arr.splice(FindEl(arr, i), arr, FindEl(arr, j));
		}
	}
	arr.splice(FindEl(arr, low), arr, FindEl(arr, j));
	return j;
}

void quickSort(std::list<int>& arr, int low, int high)
{
	if (low < high)
	{
		int p = partition(arr, low, high);
		quickSort(arr, low, p - 1);
		quickSort(arr, p + 1, high);
	}
}

int partitionArray(int* arr, int low, int high)
{
	int pivot = arr[low];
	int i = low;
	int j = high;

	while (i < j)
	{
		while (arr[i] <= pivot && i <= high - 1)
		{
			i++;
		}
		while (arr[j] > pivot && j >= low + 1)
		{
			j--;
		}
		if (i < j)
		{
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	int temp = arr[low];
	arr[low] = arr[j];
	arr[j] = temp;
	return j;
}

void quickSortArray(int* arr, int low, int high)
{
	if (low < high)
	{
		int p = partitionArray(arr, low, high);
		quickSortArray(arr, low, p - 1);
		quickSortArray(arr, p + 1, high);
	}
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

void PrintArray(int* arr,int N)
{
	std::cout << "\nArray:\n";
	for (int i = 0; i < N; i++)
	{
		std::cout << "[" << arr[i] << "] ";
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

	auto start = std::chrono::high_resolution_clock::now();

	quickSort(arr,0,arr.size()-1);

	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration = start - end;

	//Массив 
	int* Arr = new int[N];
	for (int i = 0; i < N; i++)
	{
		Arr[i] = rand() % 100000;
	}

	auto start1 = std::chrono::high_resolution_clock::now();

	quickSortArray(Arr, 0,N-1);

	auto end1 = std::chrono::high_resolution_clock::now();
	std::chrono::duration<long double> duration1 = start1 - end1;

	std::cout << "Скорость сортировки на списке при " << N << " элементах: ";
	std::cout << duration;
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