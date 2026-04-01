#include "GraphsCollection.h"

void GraphsCollection::push(int key, std::vector<int> value)
{
	keys.push_back(key);
	values.push_back(value);
}

std::vector<int> GraphsCollection::getElement(int key)
{
	for (int i = 0; i < keys.size(); i++)
	{
		if (key == keys[i])
		{
			return values[i];
		}
	}
}

int GraphsCollection::size()
{
	if (keys.size() == values.size())
	{
		return keys.size();
	}
	std::cout << "Произошла ошибка: размеры коллекции некорректны\n";
}

void GraphsCollection::append(int key, int append)
{
	for (int i = 0; i < values[key].size(); i++)
	{
		if (append == values[key][i])
		{
			return;
		}
	}
	values[key].push_back(append);
}