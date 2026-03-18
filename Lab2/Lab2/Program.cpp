#include <iostream>
#include "Orders.h"
#include "OrdersTest.h"
#include "FibonacciTest.h"
#include <clocale>
int main()
{
	setlocale(LC_ALL, "Russian");

	FibonacciTest fibonacci;
	std::cout << "Среднее время работы алгоритма Фибоначчи: " << fibonacci.testAlgorithm(100) << "\n\n";
	std::cout << "Время работы алгоритма Фибоначчи без сохранений: " << fibonacci.findFibonacciStraight(50) << "\n\n";
}