// NQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
using namespace std;
#include<iostream>

void printMat(bool **mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j] << " ";
		}
		cout << endl;
	}

}

bool canbeplaced(bool **mat, int row, int col, int size)
{
	int temprow = row, tempcol = col;

	while (temprow >= 0)
	{
		if (mat[temprow--][col] == 1)
			return false;
	}

	temprow = row, tempcol = col;
	while (tempcol >= 0)
	{
		if (mat[row][tempcol--] == 1)
			return false;
	}
	
	temprow = row, tempcol = col;
	while (temprow>=0 && tempcol>=0)
	{
		if (mat[temprow--][tempcol--] == 1)
			return false;
	}

	temprow = row, tempcol = col;
	while (temprow>=0 && tempcol>=0)
	{
		if (mat[temprow--][tempcol++] == 1)
			return false;
	}

	return true;
}


void nqueens(bool **mat, int row, int size)
{
	if (row == size)
	{
		printMat(mat, size);
		return;
	}

	for (int j = 0; j < size; j++)
	{
		if (canbeplaced(mat, row, j, size))
		{
			mat[row][j] = true;
			nqueens(mat, row + 1, size);
			mat[row][j] = false;
		}
	}
	
}


int main()
{
	bool** mat = new bool*[4];

	for (int i = 0; i < 4; i++)
	{
		mat[i] = new bool[4];

		for (int j = 0; j < 4; j++)
		{
			mat[i][j] = 0;
		}

	}
	
	nqueens(mat, 0, 5);

    return 0;
}

