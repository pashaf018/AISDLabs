#include "Order.h"

Order::Order(int valueS,int valueE)
{
	if (valueS < 0 || valueE < 0 || valueS > valueE)
	{
		return;
	}
	start = valueS;
	end = valueE;
}

int Order::getStart()
{
	return start;
}

int Order::getEnd()
{
	return end;
}