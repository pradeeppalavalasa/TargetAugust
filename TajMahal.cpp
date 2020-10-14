// TajMahal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


void printarr(int *arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

int timetakentoreach(float num, float n, float index)
{
	float temp = ceil((num - index) / n);
	return (temp*n)+ index;
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

	int min = INT_MAX;
	for (int i = 0; i<n; i++)
	{
		arr[i] = timetakentoreach(arr[i], n, i);
		if (arr[i]<min)
			min = arr[i];
	}

	for (int i = 0; i<n; i++)
	{
		if (min == arr[i])
		{
			cout << i+1 <<endl;
			return 0;
		}
	}

	return 0;
}

