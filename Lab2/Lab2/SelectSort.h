#pragma once
#include "Includes.h"
class SelectSort
{
private:
	static void swap(int&, int&);
public:
	static void selectSort(std::vector<int>&);

	static double testAlgorithm(int);
};

