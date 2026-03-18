#include "FibonacciTest.h"
#include <iostream>
long long FibonacciTest::findFibonacci(int index)
{
	for (int i = Saved.size(); i <= index; i++)
	{
		Saved.push_back(Saved[i - 1] + Saved[i - 2]);
	}
	return Saved[index];
}

double FibonacciTest::testAlgorithm(int count)
{
	double result = 0;
	for (int i = 0; i < count; i++)
	{
		int index = rand() % 93;
		time_t t1 = clock();
		findFibonacci(index);
		time_t t2 = clock();
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}
	return (double)result / count;
}

std::vector<long long> FibonacciTest::getSaved()
{
	return Saved;
}

long long FibonacciTest::findFibonacciStraight(int count)
{
	if (count == 1 || count == 0)
	{
		return count;
	}
	return  findFibonacciStraight(count-1) + findFibonacciStraight(count - 2);
}

double FibonacciTest::testStraight(int count)
{
	double result = 0;
	for (int i = 0; i < count; i++)
	{
		int index = rand() % 93;
		time_t t1 = clock();
		findFibonacciStraight(index);
		time_t t2 = clock();
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}
	return (double)result / count;
}