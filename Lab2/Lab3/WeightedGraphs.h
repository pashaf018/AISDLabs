#pragma once
#include "Includes.h"

class WeightedGraphs
{
private:
	std::vector<std::vector<int>> matrix;

	std::vector<std::vector<int>> newMatrix;
public:
	std::vector<std::vector<int>> getMatrix();

	void generateRandom(int,int,int);

	void printMatrix(int);

	int findMinGraph();
};

