// NonDivisibleSubsets.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include <algorithm> 
using namespace std;

int findMaxLenNonDivisibleSubset(vector<int> vec, int k )
{
	int res = 0;
	std::vector<int> rem(k);

	for (int i = 0; i < vec.size(); i++)
	{
		rem[vec[i] % k]++;
	}

	if (k % 2 == 0)
		rem[k / 2] = min(rem[k / 2], 1);

	res = min(rem[0], 1);
	for (int i = 1; i <= k/2; i++)
	{
		res += max(rem[i], rem[k - i]);
	}
	return res;
}


int main()
{
	vector<int> vec = { 3, 7, 2, 9, 1 };
	int ans = findMaxLenNonDivisibleSubset(vec,4);
    return 0;
}

