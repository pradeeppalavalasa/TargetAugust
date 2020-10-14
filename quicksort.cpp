// quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;



int partition(int *input, int low, int high)
{
	int pivot = input[high];
	int leftpointer = low;
	int rightpointer = high - 1;

	while (1)
	{
		while (input[leftpointer]<pivot)
			leftpointer++;

		while (rightpointer>0 && input[rightpointer]>pivot)
			rightpointer--;

		if (leftpointer<rightpointer)
		{
			int temp = input[leftpointer];
			input[leftpointer] = input[rightpointer];
			input[rightpointer] = temp;
		}
		else
			break;
	}

	int temp = input[high];
	input[high] = input[leftpointer];
	input[leftpointer] = temp;
	return leftpointer;
}

void quicksort(int *input, int low, int high)
{
	if (low >= high)
		return;

	int part = partition(input, low, high);
	quicksort(input, low, part - 1);
	quicksort(input, part + 1, high);
}


int main()
{
	int arr[3] = { 3,1,2 };
	quicksort(arr, 0, 2);
	for (int i = 0; i < 3; i++)
		cout << arr[i];
    return 0;
}

