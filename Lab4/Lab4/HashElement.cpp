#include "HashElement.h"

HashElement::HashElement(int key, int value)
{
	Key = key;
	Value = value;
	Removed = false;
}

HashElement::HashElement()
{
	Key = -1;
	Value = 0;
	Removed = true;
}