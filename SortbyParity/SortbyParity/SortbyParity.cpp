// SortbyParity.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
using namespace std;

vector<int> sortArrayByParity1(vector<int>& A) {
	int a = 0;
	for (int i = 0; i<A.size(); ++i) {
		if (A[i] % 2 == 0) {
			swap(A[a++], A[i]);
		}
	}
	return A;
}

vector<int> sortArrayByParity(vector<int>& A) {
	int low = 0;
	int high = A.size()-1;
	int temp;

	while (low < high)
	{
		while (A[low] % 2 == 0 && low < high)
			low++;

		while (A[high] % 2 == 1 && low < high)
			high--;

		temp = A[low];
		A[low] = A[high];
		A[high] = temp;

		low++;
		high--;
	}
	return A;
}


int main()
{
	vector<int> vec = { 3,1,2,4};
	vector<int> ans = sortArrayByParity1(vec);

    return 0;
}

