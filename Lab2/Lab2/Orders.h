#pragma once
#include "Order.h"
#include "Includes.h"

class Orders
{
private:
	std::vector<Order> ordersContainer;
public:
	Orders(std::vector<Order>);

	Orders();

	void push(Order);

	std::vector<Order> getOrders();
};

