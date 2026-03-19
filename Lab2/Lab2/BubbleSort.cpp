#include "BubbleSort.h"

void bubbleSort(std::vector<int> *arr)
{
	for (int i = arr->size(); i > 0; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if (arr->at(j-1) > arr->at(j))
			{
				std::swap(arr->at(j-1), arr->at(j));
			}
		}
	}
}

std::vector<int> generateRandomArray(int size)
{
	std::vector<int> arr;
	for (int i = 0; i < size; i++)
	{
		arr.push_back(rand() % 1000);
	}
	return arr;
}

void printArray(std::vector<int> arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		std::cout << "[" << arr[i] << "] ";
	}
	std::cout << "\n\n";
}

double testBubbleSort(int count)
{
	double result = 0;
	for(int i = 0;i < count;i++)
	{
		std::vector<int> arr = generateRandomArray(10000);
		time_t t1 = clock();
		bubbleSort(&arr);
		time_t t2 = clock();
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}
	return (double)result / count;
}