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
		node = new TreeNode();
		node->value = val;
	}

	if (val < node->value)
	{
		node->left = push(node->left,val);
	}
	else
	{
		node->right = push(node->right, val);
	}

	return node;
}

void Tree::generateRandom(TreeNode* root,int count)
{
	for (int i = 0; i < count; i++)
	{
		push(root, rand() % 1000);
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
}