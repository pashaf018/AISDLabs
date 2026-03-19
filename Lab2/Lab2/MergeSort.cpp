#include "MergeSort.h"

void MergeSort::mergeSort(std::vector<int>& arr,int left,int right)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;

		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);

		merge(arr, left, mid, right);
	}
}

void MergeSort::merge(std::vector<int>& arr,int left,int mid,int right)
{
	int size1 = mid - left + 1;
	int size2 = right - mid;

	std::vector<int> leftArr(size1);
	std::vector<int> rightArr(size2);

	for (int i = 0; i < size1; i++)
	{
		leftArr[i] = arr[left + i];
	}
	for (int j = 0; j < size2; j++)
	{
		rightArr[j] = arr[mid + 1 + j];
	}

	int i = 0;
	int j = 0;
	int k = left;

	while (i < size1 && j < size2)
	{
		if (leftArr[i] < rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
		k++;
	}

	while (i < size1)
	{
		arr[k] = leftArr[i];
		i++;
		k++;
	}

	while (j < size2)
	{
		arr[k] = rightArr[j];
		j++;
		k++;
	}


}