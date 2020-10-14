// bubblesort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

bool checksort(int *arr, int n)
{

	for (int i = 0; i < (n - 1); i++)
	{
		if (arr[i] > arr[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool bubblesort(int *arr, int n)
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < (n - 1); j++)
		{	
			int diff = abs(arr[j] - arr[j + 1]);
			if (diff <= 1)
			{
				if (arr[j] > arr[j + 1])
				{
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
			
		}
	}
	return checksort(arr, n);
}


int main()
{
	int testcases;
	cin >> testcases;

	while (testcases--)
	{
		int size;
		cin >> size;
		int *arr = new int[size];

		for (int i = 0; i < size; i++)
		{
			cin >> arr[i];
		}
		if(bubblesort(arr, size))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
    return 0;
}

