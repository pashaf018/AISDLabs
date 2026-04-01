//#include "Collection.h"
//
//template <typename T,typename U>
//void Collection<T, U>::push(T key, U value)
//{
//	keys.push_back(key);
//	values.push_back(value);
//}
//
//template <typename T, typename U>
//U Collection<T, U>::getElement(T key)
//{
//	for (int i = 0; i < keys.size(); i++)
//	{
//		if (keys[i] == key)
//		{
//			return values[i];
//		}
//	}
//}
//
//template <typename T,typename U>
//int Collection<T,U>::size()
//{
//	if (keys.size() == values.size())
//	{
//		return keys.size();
//	}
//	else 
//	{
//		std::cout << "Произошла ошибка: размер коллекции некорректен";
//	}
//}