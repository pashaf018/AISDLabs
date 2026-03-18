#include "Orders.h"

Orders::Orders(std::vector<Order> orders)
{
	if (orders.size() < 0)
	{
		return;
	}
	ordersContainer.swap(orders);
}

Orders::Orders()
{
	
}

void Orders::push(Order order)
{
	ordersContainer.push_back(order);
}

std::vector<Order> Orders::getOrders()
{
	return ordersContainer;
}
