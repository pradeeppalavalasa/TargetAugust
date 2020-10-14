// KConcat.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

long long int kadane(int *arr, int n)
{
	long long int cur_sum = 0, max_so_far = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		cur_sum += arr[i];
		if ( max_so_far < cur_sum )
			max_so_far = cur_sum;

		if (cur_sum < 0)
			cur_sum = 0;
	}
	return max_so_far;
}

long long int total_sum(int *arr, int n)
{
	long long int total_sum = 0;

	for (int i = 0; i < n; i++)
	{
		total_sum += arr[i];
	}
	return total_sum;
}

long long int best_prefix_sum(int *arr, int n)
{
	long long int cur_sum = 0, max_prefix_sum = INT_MIN;

	for (int i = 0; i < n; i++)
	{
		cur_sum += arr[i];
		if (max_prefix_sum < cur_sum)
			max_prefix_sum = cur_sum;
	}
	return max_prefix_sum;
}



long long int best_suffix_sum(int *arr, int n)
{
	long long int cur_sum = 0, max_suffix_sum = INT_MIN;

	for (int i = n-1; i >=0; i--)
	{
		cur_sum += arr[i];
		if (max_suffix_sum < cur_sum)
			max_suffix_sum = cur_sum;
	}
	return max_suffix_sum;
}

long long int kConcat(int *arr, int n, int k)
{
	long long int max_sum = kadane(arr, n);

	if (k == 1)
		return max_sum;

	long long int best_prefix_sum1 = best_prefix_sum(arr, n);
	long long int best_suffix_sum1 = best_suffix_sum(arr, n);
	long long int total_sum1 = total_sum(arr, n);

	if (total_sum1 >= 0)
		return std::max(best_prefix_sum1 + ((k - 2)*total_sum1) + best_suffix_sum1, max_sum);
	else
		return std::max(best_prefix_sum1 + best_suffix_sum1, max_sum);

}

int main()
{
	int testcases;
	cin >> testcases;
	while (testcases-- != 0)
	{
		int n, k;
		cin >> n >> k;
		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		cout << kConcat(arr, n, k);
	}
    return 0;
}

