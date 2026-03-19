#pragma once
#include "TreeNode.h"
class Tree
{
private:
	TreeNode* Root = nullptr;
public:
	void setRoot(TreeNode*);

	TreeNode* getRoot();

	static TreeNode* push(TreeNode*,int);

	static void generateRandom(TreeNode*,int);

	static void printTree(TreeNode*);
};

