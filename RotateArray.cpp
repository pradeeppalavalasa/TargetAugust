// RotateArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;


int gcd(int n, int d)
{
	if (d == 0)
		return n;

	return gcd(d, n%d);
}


void rotate(int *input, int d, int n)
{
	//Write your code here
	int val = gcd(n, d);

	for (int i = 0; i<val; i++)
	{
		int j = i;
		int temp = input[i];
		while (1)
		{
			int k = j + d;
			if (k >= n)
				k = k - n;

			if (k == i)
				break;

			input[j] = input[k];
			j = k;
		}
		input[j] = temp;
	}
}


int main()
{
	int arr[11] = { 1, 3, 6, 11, 12, 17, 22, 26, 30, 33, 38 };

	rotate(arr, 7, 11);

	for (int i = 0; i < 11; i++)
	{
		cout << arr[i] << " ";
	}
    return 0;
}

