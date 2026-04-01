#pragma once
#include "GraphsCollection.h"

class Graphs
{
private:
	GraphsCollection list;
	std::vector<std::vector<int>> arr;
public:

	void generateRandomList(int,int);

	void printAdjList();
};

