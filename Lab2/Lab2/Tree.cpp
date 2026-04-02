#include "Tree.h"
#include "Includes.h"
void Tree::setRoot(TreeNode* newRoot)
{
	Root = newRoot;
}

TreeNode* Tree::getRoot()
{
	return Root;
}

TreeNode* Tree::push(TreeNode* node,int val)
{
	if (node == nullptr)
	{
		TreeNode* newnode = new TreeNode(val);
		newnode->left = nullptr;
		newnode->right = nullptr;
		return newnode;
	}

	if (node->value == val)
	{
		return node;
	}

	if (val < node->value)
	{
		node->left = push(node->left,val);
	}
	else 
	{
		node->right = push(node->right,val);
	}

	return node;
}

void Tree::generateRandom(int count)
{
	for (int i = 0; i < count; i++)
	{
		push(Root, rand() % 1000);
	}
}

void Tree::printTree(TreeNode* root)
{
	if (root == nullptr)
	{
		return;
	}

	std::cout << root->value << " ";
	printTree(root->left);
	printTree(root->right);
	std::cout << "\n";
}

void Tree::destroyTree(TreeNode* node)
{
	if (node == nullptr)
	{
		Root = nullptr;
		return;
	}

	destroyTree(node->left);
	destroyTree(node->right);

	delete node;
}

int Tree::findMin(TreeNode* node)
{
	if (node->left == nullptr)
	{
		return node->value;
	}

	findMin(node->left);
}

double Tree::testBinarySearch(int count)
{
	double result = 0;

	for (int i = 0; i < count; i++)
	{
		TreeNode* root = new TreeNode(500);
		Root = root;
		generateRandom(1000000);
		time_t t1 = clock();
		findMin(Root);
		time_t t2 = clock();
		destroyTree(Root);
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}

	return (double)result / count;
}

double Tree::testArray(int count)
{
	double result = 0;
	int mas = 100000;
	int arr[100000];

	for (int i = 0; i < count; i++)
	{
		for (int j = 0; j < mas; j++)
		{
			arr[j] = rand() % 1000;
		}
		int min = arr[0];
		time_t t1 = clock();
		for (int k = 1; k < mas; k++)
		{
			if (min > arr[k])
			{
				min = arr[k];
			}
		}
		time_t t2 = clock();
		result += (double)(t2 - t1) / CLOCKS_PER_SEC;
	}

	return (double)result / count;
}