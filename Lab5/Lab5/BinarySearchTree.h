#pragma once
#include "Includes.h"

struct BinarySearchTree
{
	int Key;
	int Value;
	BinarySearchTree* left, * right;
	BinarySearchTree(int key, int value) :Key(key), Value(value), left(nullptr), right(nullptr) {}

	BinarySearchTree* findMin(BinarySearchTree*);

	BinarySearchTree* insert(BinarySearchTree*, int, int);

	BinarySearchTree* search(BinarySearchTree*, int);

	BinarySearchTree* erase(BinarySearchTree*, int);

	void deleteTree(BinarySearchTree*);

	BinarySearchTree* findAny(BinarySearchTree*);

	void toString(BinarySearchTree*);
};

