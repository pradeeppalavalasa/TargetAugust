#pragma once

class Tree
{
public:
	int data;
	Tree *left;
	Tree *right;

	Tree(int data)
	{
		this->data = data;
		this->left = nullptr;
		this->right = nullptr;
	}
};