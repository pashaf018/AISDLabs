#include "SelectSort.h"
#include "BubbleSort.h"
void SelectSort::selectSort(std::vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
	{
		int minI = i;
		for (int j = i; j < arr.size(); j++)
		{
			if (arr[minI] > arr[j])
			{
				minI = j;
			}
		}
		swap(arr[i], arr[minI]);
	}
}

void SelectSort::swap(int& el1, int& el2)
{
	int temp = el1;
	el1 = el2;
	el2 = temp;
}

double SelectSort::testAlgorithm(int count)
{
	double result = 0;


	for (int i = 0; i < count; i++)
	{
		std::vector<int> arr = generateRandomArray(1000);
		time_t t1 = clock();
		selectSort(arr);
		time_t t2 = clock();
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}

	return (double)(result / count);
}