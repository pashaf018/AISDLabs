#pragma once

class Order
{
private:
	int start = -1;
	int end = -1;
public:
	Order(int, int);
	
	int getStart();

	int getEnd();
};

