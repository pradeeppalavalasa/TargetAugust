// FallingFootBall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<string>
using namespace std;


void printVec(vector<int> vec)
{
	int first = 0;
	int last = 0;
	int max = -1;
	vector<string> vecstr;
	for (int i = 0; i < vec.size(); i++)
	{
		if (vec[i] > 0)
			last = i;

		if (vec[i] > max)
			max = vec[i];
	}

	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if (vec[i] > 0)
			first = i;
	}

	while (max-- != 0)
	{
		string str = "";
		for (int i = first; i <= last; i++)
		{
			if (vec[i] >= 1)
			{
				str = str + "O";
				vec[i]--;
			}
			else
				str = str + ".";
		}
		vecstr.push_back(str);
	}

	for (int i = vecstr.size() - 1; i >= 0; i--)
	{
		cout << vecstr[i];
		cout << "\n";
	}
}


void fillballpos(vector<int> &vec, int pos)
{
	if ((vec[pos] - vec[pos + 1] <= 0 && vec[pos] - vec[pos - 1] <= 0) || vec[pos] == 0)
	{
		vec[pos]++;
		return;
	}

	if (vec[pos] - vec[pos + 1] >= 1)
		fillballpos(vec, pos + 1);

	else if (vec[pos] - vec[pos - 1] >= 1)
		fillballpos(vec, pos - 1);

	return;
}

int main()
{
	int testcases, size, pos;
	cin >> testcases;
	int index = 1;
	while (testcases-- != 0)
	{
		cin >> size;
		vector<int> vec((2 * 20) + 2);
		vector<int> vecpos;
		for (int i = 0; i < size; i++)
		{
			cin >> pos;
			fillballpos(vec, pos + 20);
		}
		cout << "Case " << index << ":\n";
		printVec(vec);
		index++;

	}
	getchar();
	return 0;
}

