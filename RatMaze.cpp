// RatMaze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

void printMat(bool **mat, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << mat[i][j] << " ";
		}
		
	}
	cout << endl;
}

void ratmaze(int maze[3][3], int row, int col, int size, bool **ans)
{
	if (row == size-1 && col == size-1)
	{
		ans[row][col] = 1;
		printMat(ans, size);
		return;
	}
	else if (row <= size && row > -1 && col <= size && col > -1 && maze[row][col] == 1&& ans[row][col]!=1)
	{
		ans[row][col] = 1;
		ratmaze(maze, row, col+1, size, ans);
		ratmaze(maze, row+1, col, size, ans);
		ratmaze(maze, row - 1, col, size, ans);
		ratmaze(maze, row, col-1, size, ans);
		ans[row][col] = 0;

	}
}


int main()
{
	int a[][3] = { { 1,0,1 },{1,0,1 },{ 1,1,1 } };

	int num = 3;
	bool** mat = new bool*[num];

	for (int i = 0; i < num; i++)
	{
		mat[i] = new bool[num];

		for (int j = 0; j < num; j++)
		{
			mat[i][j] = 0;
		}

	}

	ratmaze(a, 0, 0, num, mat);
    return 0;
}

