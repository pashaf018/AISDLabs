#include "HashElement.h"

HashElement::HashElement(int key, int value)
{
	Key = key;
	Value = value;
	Removed = false;
}

HashElement::HashElement()
{
	Removed = true;
}