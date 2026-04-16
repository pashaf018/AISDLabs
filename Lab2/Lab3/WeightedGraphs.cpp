#include "WeightedGraphs.h"

std::vector<std::vector<int>> WeightedGraphs::getMatrix()
{
	return matrix;
}

void WeightedGraphs::generateRandom(int count, int maxConnections,int maxWeight)
{
	for (int i = 0; i < count; i++)
	{
		std::vector<int> adjList(count,0);
		matrix.push_back(adjList);
	}

	for (int i = 0; i < count; i++)
	{
		int con = rand() % maxConnections + 1;
		for (int j = 0; j < con; j++)
		{
			if (i == j)
			{
				continue;
			}
			int weight = rand() % maxWeight;
			int join = rand() % count;

			matrix[i][join] = weight;
			matrix[join][i] = weight;
		}

	}
}

void WeightedGraphs::printMatrix(int flag)
{
	std::vector<std::vector<int>> huh;
	if (flag == 0)
	{
		huh = matrix;
	}
	else
	{
		huh = newMatrix;
	}
	std::cout << "    ";
	for (int i = 0; i < huh.size(); i++)
	{
		std::cout << "[" << i + 1 << "]\t";
	}

	for (int i = 0; i < huh.size(); i++)
	{
		std::cout << "\n[" << i + 1 << "] ";
		for (int j = 0; j < huh.size(); j++)
		{
			if (j == i)
			{
				std::cout << "*\t";
				continue;
			}
			std::cout << huh[i][j] << " \t";
		}
	}
	std::cout << "\n\n";
}

int WeightedGraphs::findMinGraph()
{
	std::vector<int> keys(matrix.size(),INT_MAX);
	std::vector<int> memory(matrix.size(),0);
	std::vector<int> visited(matrix.size(), 0);
	keys[0] = 0;
	std::priority_queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int toLook = q.top();
		q.pop();
		if (visited[toLook] == 1)
		{
			continue;
		}
		visited[toLook] = 1;
		for (int i = 0; i < matrix.size(); i++)
		{
			if (matrix[toLook][i] > 0 && keys[i] > matrix[toLook][i] && visited[i] == 0)
			{
				memory[i] = toLook;
				keys[i] = matrix[toLook][i];
				q.push(i);
				std::cout << "Рассматриваемый элемент: " << toLook + 1 << std::endl;
				for (int j = 0; j < matrix.size(); j++)
				{
					std::cout << keys[j] << " ";
				}
				std::cout << std::endl;
				for (int j = 0; j < matrix.size(); j++)
				{
					std::cout << memory[j] << " ";
				}
				std::cout << std::endl;
			}
		}
	}
	
	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<int> oop(matrix.size(), 0);
		newMatrix.push_back(oop);
	}
	/// сборка
	for (int i = 0; i < memory.size(); i++)
	{
		newMatrix[i][memory[i]] = keys[i];
		newMatrix[memory[i]][i] = keys[i];
	}
	int result = 0;
	for (int i = 0; i < newMatrix.size(); i++)
	{
		for (int j = i; j < newMatrix.size(); j++)
		{
			result += newMatrix[i][j];
		}
	}
	return result;
}