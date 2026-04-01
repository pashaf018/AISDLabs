#pragma once
#include "Includes.h"

class GraphsCollection
{
private:
	std::vector<int> keys;
	std::vector<std::vector<int>> values;
public:
	void push(int, std::vector<int>);

	std::vector<int> getElement(int);

	int size();

	void append(int,int);


};

