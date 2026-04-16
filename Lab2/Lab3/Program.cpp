#include "Includes.h"
#include "Graphs.h"
#include "WeightedGraphs.h"

void printVisited(int[], int);

void printQueue(std::queue<int>);

int main()
{
	setlocale(LC_ALL, "Russian");

	/// Task CommonGraphs

	/*Graphs graphs = Graphs();
	const int size = 5;
	graphs.generateRandomList(size, 4);
	graphs.printAdjList();

	GraphsCollection list = graphs.getList();

	int visited[size];
	for (int i = 0; i < size; i++)
	{
		visited[i] = 0;
	}

	std::queue<int> q;

	q.push(0);
	while (!q.empty())
	{
		int visiting = q.front();
		if (visited[visiting] == 1)
		{
			q.pop();
			continue;
		}
		visited[visiting] = 1;
		q.pop();

		std::vector<int> newVisiting = list.getElement(visiting);
		for (int i = 0; i < newVisiting.size(); i++)
		{
			if(visited[newVisiting[i]] == 0)
			{
				q.push(newVisiting[i]);
			}
		}
		printQueue(q);
		printVisited(visited, size);
	}

	printQueue(q);
	printVisited(visited, size);*/




	/// Task WeighedGraphs

	WeightedGraphs graph = WeightedGraphs();
	int size = 5;
	graph.generateRandom(size,3,40);
	graph.printMatrix(0);

	std::vector<int> visited(size, INT_MAX);
	visited[0] = 0;

	int res = graph.findMinGraph();
	graph.printMatrix(1);
	std::cout << res;
	
}

void printVisited(int visited[],int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << i << " == " << visited[i] << std::endl;
	}
	std::cout << "------------------------------" << std::endl;
}

void printQueue(std::queue<int> q)
{
	while (!q.empty())
	{
		std::cout << q.front() << " -> ";
		q.pop();
	}
	std::cout << "\n\n";
}