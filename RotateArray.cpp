// RotateArray.cpp : Defines the entry point for the console application.
//

//Rotate array
//Send Feedback
//You have been given a random integer array / list(ARR) of size N.Write a function that rotates the given array / list by D elements(towards the left).
//Note:
//Change in the input array / list itself.You don't need to return or print the elements.
//Input format :
//The first line contains an Integer 't' which denotes the number of test cases or queries to be run.Then the test cases follow.
//
//First line of each test case or query contains an integer 'N' representing the size of the array / list.
//
//Second line contains 'N' single space separated integers representing the elements in the array / list.
//
//Third line contains the value of 'D' by which the array / list needs to be rotated.
//Output Format :
//For each test case, print the rotated array / list in a row separated by a single space.
//
//Output for every test case will be printed in a separate line.

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

