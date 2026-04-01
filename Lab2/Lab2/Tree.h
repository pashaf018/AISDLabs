#pragma once
#include "TreeNode.h"
class Tree
{
private:
	TreeNode* Root = nullptr;
public:
	void setRoot(TreeNode*);

	TreeNode* getRoot();

	TreeNode* push(TreeNode*,int);

	void generateRandom(int);

	void printTree(TreeNode*);

	void destroyTree(TreeNode*);

	double testBinarySearch(int);

	int findMin(TreeNode*);

	static double testArray(int);
};

