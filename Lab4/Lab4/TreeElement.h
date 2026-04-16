#pragma once

struct TreeElement
{
	int Value;
	TreeElement* Right;
	TreeElement* Left;

	TreeElement()
	{
		Right = nullptr;
		Left = nullptr;
	}

	TreeElement(int value)
	{
		Value = value;
		Right = nullptr;
		Left = nullptr;
	}
};