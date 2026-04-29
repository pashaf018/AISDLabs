#include "BinarySearchTree.h"

BinarySearchTree* BinarySearchTree::findMin(BinarySearchTree* root)
{
	if (root == nullptr)
	{
		return root;
	}
	while (root->left != nullptr)
	{
		root = root->left;
	}
	return root;
}

BinarySearchTree* BinarySearchTree::insert(BinarySearchTree* root,int key, int value)
{
	if (root == nullptr) { return new BinarySearchTree(key, value); }
	if (key < root->Key)
	{
		root->left = insert(root->left, key, value);
	}
	else
	{
		root->right = insert(root->right, key, value);
	}
	return root;
}

BinarySearchTree* BinarySearchTree::search(BinarySearchTree* root, int key)
{
	if (root == nullptr || root->Key == key)
	{
		return root;
	}
	if (key < root->Key)
	{
		return search(root->left, key);
	}
	return search(root->right, key);
}

BinarySearchTree* BinarySearchTree::erase(BinarySearchTree* root, int key)
{
	if (root == nullptr)
	{
		return root;
	}

	if (key < root->Key)
	{
		root->left = erase(root->left, key);
	}
	else if (key > root->Key)
	{
		root->right = erase(root->right, key);
	}
	else
	{
		if (root->left == nullptr)
		{
			BinarySearchTree* temp = root->right;
			delete root;
			return temp;
		}
		else if (root->right == nullptr)
		{
			BinarySearchTree* temp = root->left;
			delete root;
			return temp;
		}

		BinarySearchTree* temp = findMin(root->right);
		root->Key = temp->Key;
		root->Value = temp->Value;
		root->right = erase(root->right, temp->Key);
	}
	return root;
}

void BinarySearchTree::deleteTree(BinarySearchTree* root)
{
	if (root == nullptr)
	{
		return;
	}

	deleteTree(root->left);
	deleteTree(root->right);

	delete root;
}

BinarySearchTree* BinarySearchTree::findAny(BinarySearchTree* root)
{
	if (root->left == nullptr && root->right == nullptr)
	{
		return root;
	}
	if (root->left == nullptr)
	{
		return findAny(root->right);
	}
	if (root->right == nullptr)
	{
		return findAny(root->left);
	}
}

void BinarySearchTree::toString(BinarySearchTree* root)
{
	if (!root) {
		return;
	}
	toString(root->left);
	std::cout << "(" << root->Key << ":" << root->Value << ") ";
	toString(root->right);
}

