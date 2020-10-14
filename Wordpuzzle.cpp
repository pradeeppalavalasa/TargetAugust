
#include"stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
using namespace std;

void printMat(char **mat, int size)
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

bool findempty(char **board, int &row, int &col)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == '-')
			{
				row = i;
				col = j;
				return true;
			}
		}

	}
	return false;
}

void placestring(char **board, int row, int col, string str, bool isHor)
{
	int index = 0;
	if (isHor)
	{
		while (col < 10 && index<str.length())
		{
			board[row][col++] = str[index++];
		}
	}
	else
	{
		while (row < 10 && index<str.length())
		{
			board[row++][col] = str[index++];
		}
	}
	
}

void removestring(char **board, int row, int col, string str, bool isHor)
{
	int index = 0;
	if (isHor)
	{
		while (col < 10 && index<str.length())
		{
			board[row][col++] = '-';
		}
	}
	else
	{
		while (row < 10 && index<str.length())
		{
			board[row++][col] = '-';
		}
	}

}

bool canbeplaced(char **board, int row, int col, string str, bool &isHor)
{
	int freespaces = 0;
	while (row < 10)
	{
		if (board[row++][col] == '-')
			freespaces++;
		else if(board[row++][col]=='+')
			break;
		else if (board[row++][col] != str[++freespaces])
		{
			--freespaces;
			break;
		}
		else
			freespaces++;


	}

	if (freespaces >= str.length())
	{
		isHor = false;
		return true;
	}


	freespaces = 0;
	while (col < 10)
	{
		if (board[row][col++] == '-')
			freespaces++;
		else if (board[row][col++] == '+')
			break;
		else if (board[row][col++] != str[++freespaces])
		{
			--freespaces;
			break;
		}
		else
			freespaces++;
	}

	if (freespaces >= str.length())
	{
		isHor = true;
		return true;
	}

	return false;
}

bool wordpuzzle(char **board, vector<string> inputWords)
{
	int row = -1, col = -1;
	if (!findempty(board, row, col))
		return true;

	for (int i = 1; i < inputWords.size(); i++)
	{
		bool isHor = false;
		if (canbeplaced(board, row, col, inputWords[i], isHor))
		{
			placestring(board, row, col, inputWords[i], isHor);
			printMat(board, 10);
			if (wordpuzzle(board, inputWords))
				return true;
			removestring(board, row, col, inputWords[i], isHor);
		}
	}

	return false;
}

bool isValidHor(char **board, int row, int col, string str)
{
	int index = 0;
	while (row < 10 && (board[row][col] == '-' || board[row][col] == str[index]))
	{
		row++;
		index++;
	}
		

	return index >= str.length();
}

bool isValidVertical(char **board, int row, int col, string str)
{
	int index = 0;
	while (col < 10 && (board[row][col] == '-' || board[row][col] == str[index]))
	{
		index++;
		col++;
	}


	return index >= str.length();
}

void setVertical(char **board, int row, int col, string str, bool* helper)
{
	int index = 0;
	while (col < 10 && index<str.length())
	{
		if (board[row][col] == '-')
		{
			board[row][col] = str[index];
			helper[index] = true;
		}
		index++;
		col++;
	}
}

void setHor(char **board, int row, int col, string str, bool* helper)
{
	int index = 0;
	while (row < 10 && index<str.length())
	{
		if (board[row][col] == '-')
		{
			board[row][col] = str[index];
			helper[index] = true;
		}
		index++;
		row++;
	}
}

void resetVertical(char **board, int row, int col, string str, bool* helper)
{
	int index = 0;
	while (col < 10 && index<str.length())
	{
		if (helper[index])
		{
			board[row][col] = '-';
		}
		index++;
		col++;
	}
}


void resetHor(char **board, int row, int col, string str, bool* helper)
{
	int index = 0;
	while (row < 10 && index<str.length())
	{
		if (helper[index])
		{
			board[row][col] = '-';
		}
		index++;
		row++;
	}
}

bool crossword(char **board, vector<string> inputWords, int index)
{
	if (index == inputWords.size())
	{
		printMat(board, 10);
		return true;
	}
		

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			string str = inputWords[index];
			if (board[i][j] == '-' || str[0] == board[i][j])
			{
				if (isValidVertical(board, i, j, str))
				{
					bool *helper = new bool[str.length()];
					setVertical(board, i, j, str, helper);
					if (crossword(board, inputWords, index + 1))
						return true;
					resetVertical(board, i, j, str, helper);
				}

				if (isValidHor(board, i, j, str))
				{
					bool *helper = new bool[str.length()];
					setHor(board, i, j, str, helper);
					if (crossword(board, inputWords, index + 1))
						return true;
					resetHor(board, i, j, str, helper);
				}
			}
		}
	}
	return false;
}

int main()
{
	int size = 10;
	char **mat = new char*[size];
	string str;
	for (int i = 0; i < size; i++)
	{
		mat[i] = new char[size];
		std:cin >> str;
		for (int j = 0; j < size; j++)
		{
			mat[i][j] = str[j];
		}
	}

	vector<string> inputWords;
	string input, word;
	cin >> input;
	stringstream s(input);
	while (getline(s, word, ';')) {
		inputWords.push_back(word);
	}

	//wordpuzzle(mat, inputWords, 0);
	crossword(mat, inputWords, 0);
	printMat(mat, 10);
	return 0;
}

