// CountingBits.cpp : Defines the entry point for the console application.
//
//Given a non negative integer number num.For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//Example 1:
//
//Input: 2
//	Output : [0, 1, 1]
//	Example 2 :
//
//	Input : 5
//	Output : [0, 1, 1, 2, 1, 2]

#include "stdafx.h"
#include<vector>
using namespace std;

vector<int> countBits(int num) {

	vector<int> ans(num + 1, 0);

	for (int i = 1; i <= num; i++)
		ans[i] = ans[i / 2] + i % 2;

	return ans;
}

int main()
{
	vector<int> ans = countBits(10);
    return 0;
}

