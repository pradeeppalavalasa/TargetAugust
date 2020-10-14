// DistributeCandies.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

bool isValid(int *arr, int n, int k,int mid)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += arr[i] / mid;
	}
	return temp >= k;
}

int distributeCandies(int *arr, int n, int k)
{
	int low = 1;
	int high = 1000000000;
	int ans = 0;
	while (low <= high)
	{
		int mid = low + (high - low + 1) / 2;
		if (isValid(arr, n, k, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return ans;
}


int main()
{
	int testcases;
	cin >> testcases;

	while (testcases--)
	{
		int n, k;
		cin >> n >> k;
		int *arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		cout << distributeCandies(arr, n, k) << endl;
	}
    return 0;
}

