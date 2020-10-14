// AggressiveCows.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;

bool isvalid(int *arr, int stalls, int num_cows, int distance)
{
	long long last_cow_placed = arr[0];
	int temp = 1;

	for (int i = 1; i < stalls; i++)
	{
		if (arr[i] - last_cow_placed >= distance)
		{
			temp++;
			if (temp == num_cows)
				return true;
			last_cow_placed = arr[i];
		}
	}
	return false;
}


int aggresivecows(int *arr, int stalls, int num_cows)
{
	sort(arr, arr + stalls);
	int low = 0;
	int high = arr[stalls - 1];
	int mid;
	int ans = 0;
	while (low <= high)
	{
		mid = (low + high)/2;
		if (isvalid(arr, stalls, num_cows, mid))
		{
			ans = mid;
			low = mid;
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
		int stalls, num_cows;
		cin >> stalls >> num_cows;

		int * arr = new int[stalls];

		for (int i = 0; i < stalls; i++)
		{
			cin >> arr[i];
		}

		cout << aggresivecows(arr, stalls, num_cows);
	}
    return 0;
}

