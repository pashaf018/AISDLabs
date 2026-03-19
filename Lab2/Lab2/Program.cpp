#include "OrdersTest.h"
#include "FibonacciTest.h"
#include "BubbleSort.h"
#include "MergeSort.h"
#include "Tree.h"
int main()
{
	setlocale(LC_ALL, "Russian");

	/*double res = testBubbleSort(100);
	std::cout << "Среднее время сортировки пузырьком: " << res;*/

	/*std::vector<int> arr = generateRandomArray(10);
	printArray(arr);
	MergeSort::mergeSort(arr,0,arr.size()-1);
	printArray(arr);*/

	TreeNode* node = new TreeNode();
	Tree::generateRandom(node, 5);
	Tree::printTree(node);
	

	//FibonacciTest fibonacci;
	//std::cout << "Среднее время работы алгоритма Фибоначчи: " << fibonacci.testAlgorithm(100) << "\n\n";
	//std::cout << "Время работы алгоритма Фибоначчи без сохранений: " << fibonacci.findFibonacciStraight(50) << "\n\n";
}