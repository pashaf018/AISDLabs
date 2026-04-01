#include "OrdersTest.h"
#include "FibonacciTest.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "Tree.h"
#include "SelectSort.h"
int main()
{
	setlocale(LC_ALL, "Russian");

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

	/*double res = testBubbleSort(100);
	std::cout << "Среднее время сортировки пузырьком: " << res;*/

	/*std::vector<int> arr = generateRandomArray(10);
	printArray(arr);
	MergeSort::mergeSort(arr,0, 9);
	printArray(arr);
	std::cout << "Среднее время сортировки слиянием: " << MergeSort::testMergeSorting(100);*/

	/*TreeNode* node = new TreeNode();
	node->value = 500;
	node->right = nullptr;
	node->left = nullptr;
	Tree tree = Tree();
	std::cout << "Среднее время поиска в двоичном дереве: " << tree.testBinarySearch(10);
	std::cout << "\nСреднее время поиска в массиве: " << Tree::testArray(10);*/

	//FibonacciTest fibonacci;
	//std::cout << "Среднее время работы алгоритма Фибоначчи: " << fibonacci.testAlgorithm(100) << "\n\n";
	//std::cout << "Время работы алгоритма Фибоначчи без сохранений: " << fibonacci.findFibonacciStraight(50) << "\n\n";
}