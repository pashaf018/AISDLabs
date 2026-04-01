#include "Graphs.h"
#include "Includes.h"

GraphsCollection Graphs::getList()
{
	return list;
}

void Graphs::generateRandomList(int count,int maxConnections)
{
	for (int i = 0; i < count; i++)
	{
		std::vector<int> adjList;
		list.push(i, adjList);
	}

	for (int i = 0; i < count; i++)
	{
		int connections = rand() % maxConnections + 1;
		for (int j = 0; j < connections; j++)
		{
			int join = rand() % count;
			if (join == i)
			{
				continue;
			}
			list.append(i, join);
			list.append(join, i);
		}
	}
}

void Graphs::printAdjList()
{
	for (int i = 0; i < list.size(); i++)
	{
		std::cout << "[" << i << "] = ";

		std::vector<int> arr = list.getElement(i);
		for (int j = 0; j < arr.size(); j++)
		{
			std::cout << arr[j] << " -> ";
		}
		std::cout << "\n";
	}
}