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
	int result = 0;
	std::vector<std::vector<int>> newmatrix;
	std::vector<int> visited(matrix.size(), 0);
	for (int i = 0; i < matrix.size(); i++)
	{
		std::vector<int> push(matrix.size(), 0);
		newmatrix.push_back(push);
	}

	std::queue<int> q;

	q.push(0);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (visited[v] == 1)
		{
			continue;
		}
		visited[v] = 1;
		int min = INT_MAX;
		int minI = 0;
		for(int i = 0;i < matrix.size();i++)
		{
			if (matrix[v][i] > 0 && min > matrix[v][i])
			{
				min = matrix[v][i];
				minI = i;
			}
		}
		newmatrix[v][minI] = matrix[v][minI];
		if (visited[minI] == 1)
		{
			continue;
		}
		q.push(minI);
	}

	/// correcting

	for (int i = 0; i < newmatrix.size(); i++)
	{
		for (int j = 0; j < newmatrix.size(); j++)
		{
			if (newmatrix[i][j] != newmatrix[j][i] && newmatrix[i][j] != 0)
			{
				newmatrix[j][i] = newmatrix[i][j];
			}
			else {
				newmatrix[i][j] = newmatrix[j][i];
			}
		}
	}

	newMatrix = newmatrix;

	return result;
}

int WeightedGraphs::findMinGraphPirated()
{
	int result = 0;
	std::vector<int> used(matrix.size(), 0);

	std::priority_queue<std::pair<int,int>,std::vector<std::pair<int, int>>,std::greater<std::pair<int, int>>> q;
	q.push({ 0,0 });

	while (!q.empty())
	{
		std::pair<int, int> c = q.top();
		q.pop();

		int dest = c.first;
		int v = c.second;

		if (used[v] == 1)
		{
			continue;
		}

		used[v] = 1;
		result += 
	}
}