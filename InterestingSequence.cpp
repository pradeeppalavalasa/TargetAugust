// InterestingSequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

int findmax(int *arr, int n)
{
	int max = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

int findmin(int *arr, int n)
{
	int min = INT_MAX;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] < min)
			min = arr[i];
	}
	return min;
}

int calccost(int *arr, int n, int k, int l, int val)
{
	int inc=0,dec=0;
	for (int i = 0; i < n; i++)
	{
		if (arr[i] > val)
			dec += arr[i] - val;
		else
			inc += val - arr[i];
	}

	if (inc >= dec)
		return dec*k + (inc - dec)*l;

	return INT_MAX;
}

int interestingSeq(int *arr, int n, int k, int l)
{
	int min = findmin(arr, n);
	int max = findmax(arr, n);
	int mincost = INT_MAX;

	for (int i = min; i <= max; i++)
	{
		int cost = calccost(arr, n, k, l, i);
		if (cost < mincost)
			mincost = cost;
	}
	return mincost;
}

int main()
{
	int n,k,l;
	cin >> n>>k>>l;
	int *arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	cout << interestingSeq(arr, n, k,l);

    return 0;
}

