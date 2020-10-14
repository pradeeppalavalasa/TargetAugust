// SolveSudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
using namespace std;

void printMat(int **mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j];
		}
		cout << endl;
	}
	
}

bool findempty(int **board, int &row, int &col)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (board[i][j] == 0)
			{
				row = i;
				col = j;
				return true;
			}
		}

	}
	return false;
}

bool canbeplaced(int **board, int row, int col, int num)
{
	for (int i = 0; i < 9; i++)
	{
		if (board[row][i] ==num)
		{
			return false;
		}
	}

	for (int i = 0; i < 9; i++)
	{
		if (board[i][col] == num)
		{
			return false;
		}
	}

	int row_start = (row / 3) * 3;
	int col_start = (col / 3) * 3;

	for (int i = row_start; i < row_start+3; i++)
	{
		for (int j = col_start; j < col_start+3; j++)
		{
			if (board[i][j] == num)
			{
				return false;
			}
		}

	}
	return true;
}

bool solvesudoku(int **board)
{
	int row = -1, col = -1;
	if (!findempty(board, row, col))
		return true;

	for (int i = 1; i < 10; i++)
	{
		if (canbeplaced(board, row, col, i))
		{
			board[row][col] = i;
			if (solvesudoku(board))
				return true;
			board[row][col] = 0;
		}
	}

	return false;
}


int main()
{

	int **mat = new int*[9];
	string str;
	for (int i = 0; i < 9; i++)
	{
		mat[i] = new int[9];
		std:cin >> str;
		for (int j = 0; j < 9; j++)
		{
			mat[i][j] = str[j] - '0';
		}
	}

	solvesudoku(mat);


	printMat(mat, 9);
    return 0;
}

