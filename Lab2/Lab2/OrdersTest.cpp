#include "OrdersTest.h"
#include <iostream>
#include <ctime>
std::vector<Order> OrdersTest::generateRandom(int count, int maxLenght)
{
	std::vector<Order> arr;
	for (int i = 0; i < count; i++)
	{
		int start = std::rand() % Distribution;
		Order temp = Order(start, start + (std::rand() % maxLenght) + 1);
		arr.push_back(temp);
	}
	return arr;
}

double OrdersTest::testAlgorithm(int count)
{
	double result = 0;
	for (int i = 0; i < count; i++)
	{
		Orders orders = Orders(OrdersTest::generateRandom(10, 100));
		printOrders(orders.getOrders());
		time_t t1 = clock();
		Orders solved = Orders(OrdersAlgorithm(sortOrders(orders.getOrders())));
		time_t t2 = clock();
		printOrders(solved.getOrders());
		std::cout << "____________________________________________________\n";
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}
	return (double)result / count;
}

std::vector<Order> OrdersTest::sortOrders(std::vector<Order> unsorted)
{
	for (int i = 1; i < unsorted.size(); i++)
	{
		Order key = unsorted[i];
		int j = i;
		while (j > 0 && key.getEnd() < unsorted[j-1].getEnd())
		{
			std::swap(unsorted[j],unsorted[j-1]);
			j--;
		}
		unsorted[j] = key;
	}
	return unsorted;
}

void OrdersTest::printOrders(std::vector<Order> orders)
{
	for (int i = 0; i < orders.size(); i++)
	{
		std::cout << "(" << orders[i].getStart() << "," << orders[i].getEnd() << ") ";
	}
	std::cout << "\n\n";
}

Orders OrdersTest::OrdersAlgorithm(std::vector<Order> sorted)
{
	Orders solved;
	solved.push(sorted[0]);
	int lastAdded = sorted[0].getEnd();
	for (int i = 1; i < sorted.size(); i++)
	{
		if (lastAdded <= sorted[i].getStart())
		{
			solved.push(sorted[i]);
			lastAdded = sorted[i].getEnd();
		}
	}
	return solved;
}

bool OrdersTest::isOrdersSorted(std::vector<Order> orders)
{
	int last = orders[0].getEnd();
	for (int i = 1; i < orders.size(); i++)
	{
		if (last > orders[i].getStart()) 
		{
			return false;
		}
		last = orders[i].getEnd();
	}
	return true;
}
