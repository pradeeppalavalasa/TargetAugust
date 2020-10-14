// MomosMarket.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void merge(int *input, int low, int mid, int high)
{
	int i = low;
	int j = mid + 1;
	int index = 0;
	int *temp = new int[high - low + 1];

	while (i <= mid && j <= high)
	{
		if (input[i]<input[j])
			temp[index++] = input[i++];
		else
			temp[index++] = input[j++];
	}

	while (i <= mid)
	{
		temp[index++] = input[i++];
	}

	while (j <= high)
	{
		temp[index++] = input[j++];
	}

	for (int k = 0; k<(high - low + 1); k++)
		input[k + low] = temp[k];
}

void mergesort(int *input, int low, int high)
{
	if (low>=high)
		return;

	int mid = low + (high - low) / 2;
	mergesort(input, low, mid);
	mergesort(input, mid + 1, high);
	merge(input, low, mid, high);
}

void momomarket(int *arr, int n, int *rem, int q)
{
	for (int i = 1; i<n; i++)
	{
		arr[i] = arr[i] + arr[i - 1];
	}
	std::vector<int> vec(arr, arr + n);

	for (int i = 0; i<q; i++)
	{
		std::vector<int>::iterator low1 = std::lower_bound(vec.begin(), vec.end(), rem[i]);
		if(*low1==rem[i])
			cout << low1 - vec.begin()+1 << " " << 0 << endl;
		else
			cout << low1 - vec.begin() << " "<<rem[i] - arr[low1 - vec.begin()-1] << endl;
	}
}

int main()
{
	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i<n; i++)
	{
		cin >> arr[i];
	}
	

	//momomarket(arr, n, rem, q);


	mergesort(arr, 0, n-1);
	for (int i = 0; i<n; i++)
	{
		cout << arr[i]<<" ";
	}
	return 0;
}


