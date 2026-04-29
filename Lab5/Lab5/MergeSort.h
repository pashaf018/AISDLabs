#pragma once
#include "Includes.h"
//Teto(n*log n)
class MergeSort
{
private:
	static void merge(std::vector<int>&, int, int, int);

public:
	static void mergeSort(std::vector<int>&, int, int);

	static double testMergeSorting(int);

};