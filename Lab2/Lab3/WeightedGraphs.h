#pragma once
#include "Includes.h"

class WeightedGraphs
{
private:
	std::vector<std::vector<int>> matrix;

public:
	std::vector<std::vector<int>> getMatrix();

	void generateRandom(int);
};

