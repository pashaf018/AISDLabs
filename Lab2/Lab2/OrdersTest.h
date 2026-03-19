#pragma once
#include "Orders.h"

class OrdersTest
{
private:
	static const int Distribution = 901;
public:
	static std::vector<Order> generateRandom(int, int);

	static double testAlgorithm(int);

	static std::vector<Order> sortOrders(std::vector<Order>);

	static void printOrders(std::vector<Order>);

	static Orders OrdersAlgorithm(std::vector<Order>);

	static bool isOrdersSorted(std::vector<Order>);
};

