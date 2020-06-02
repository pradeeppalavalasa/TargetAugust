// InvertBinaryTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InvertBinaryTree.h"
#include<iostream>
using namespace std;


void print(Tree* root)
{
	if (root == nullptr)
		return;

	cout << root->data;
	print(root->left);

	print(root->right);
}

Tree* createBinaryTree()
{


	Tree* root = new Tree(4);
	root->left = new Tree(2);
	root->right = new Tree(7);

	root->left->left = new Tree(1);
	root->left->right = new Tree(3);


	root->right->left = new Tree(6);
	root->right->right = new Tree(9);



	return root;
}

Tree* InvertBinaryTreee(Tree* root)
{
	if (root == nullptr)
		return root;

	Tree* roottemp = root->left;
	root->left = InvertBinaryTreee(root->right);
	root->right = InvertBinaryTreee(roottemp);

	return root;
}


int main()
{
	Tree* root = createBinaryTree();
	Tree *rootinv = InvertBinaryTreee(root);
	print(rootinv);
    return 0;
}

