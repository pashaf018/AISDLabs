#pragma once
#include <vector>
#include <ctime>
class FibonacciTest
{
private:
	std::vector<long long> Saved{0,1};
public:
	double testAlgorithm(int);

	long long findFibonacci(int);

	std::vector<long long> getSaved();

	static long long findFibonacciStraight(int);

	static double testStraight(int);
};

