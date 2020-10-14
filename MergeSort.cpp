// MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;

long long ans = 0;
#define SWAP(a,b,c)(c t;t=a,a=b,b=t)

class STring{
public:
	explicit STring(char ch, int n = 1) {}
	STring(const char* p) {}
private:
	void operator=(const char*) {}
};

void merge(long long arr[], long long start, long long mid, long long end)
{
	long long i = start, j = mid , index = 0;
	long long *temp = new long long[end - start + 1];

	while ((i <= mid-1) && (j <= end))
	{
		if (arr[i] <= arr[j]) 
		{
			temp[index++] = arr[i++];
		}	
		else
		{
			temp[index++] = arr[j++];
			ans += mid - i;
		}
			
	}

	while (i <= mid-1)
	{
		temp[index++] = arr[i++];
	}

	while (j <= end)
	{
		temp[index++] = arr[j++];
	}

	for (int k = 0; k < end-start+1; k++)
	{
		arr[k+start] = temp[k];
	}
}

void mergesort(long long arr[], long long start, long long end)
{
	if (start >= end)
		return;

	long long mid = (start + end) / 2;

	mergesort(arr, start, mid);
	mergesort(arr, mid+1, end);
	merge(arr, start, mid, end);

}


int main()
{
	/*long long arr[31] = {
		687176338, 289837621, 687176338, 941575810 ,783231857 ,462056296, 172999051 ,971906113, 684533604, 75682691,
		685306490, 23633765, 964542384, 343752255, 157473882, 520596748, 781207617, 58240683, 604998138, 941111217,
		536943549, 585033793, 16112334 ,146772209, 628477534, 168738081, 358041337, 3914733, 663306853, 335392934, 786330443 };

	mergesort(arr, 0, 2);
	for (int i = 0; i < 30; i++)
	{
		cout << arr[i] << " ";
	}
	cout << ans;*/
	/*int x = 50, y = 100;
	SWAP(x, y, int);
	cout << x << y;*/

	char str1[] = "Hello";
	char str2[] = "World";

	STring x = "aaa";


    return 0;
}

