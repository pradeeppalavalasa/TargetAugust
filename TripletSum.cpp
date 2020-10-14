// TripletSum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<algorithm>
#include<unordered_map>
#include<unordered_set>

//void pairSum(int *input, int n, int sum)
//{
//	//sort(input, input + n);
//	unordered_map<int, int> map_ele;
//
//	for (int i = 0; i < n; i++)
//	{
//		int rem = sum - input[i];
//		if (map_ele.find(rem) != map_ele.end()) {
//			int count = map_ele[rem];
//			for (int j = 0; j < count; j++)
//				cout << input[i-1] << " " << input[i] <<" "<<rem<< endl;
//		}
//
//		map_ele[input[i]]++;
//
//	}
//}

void print_ele(int a, int b , int c)
{
	vector<int> ele;
	ele.push_back(a);
	ele.push_back(b);
	ele.push_back(c);
	sort(ele.begin(), ele.begin() + 3);

	for (int i = 0; i < 3; i++)
	{
		cout << ele[i] << " ";
	}
	cout << endl;
}

void FindTriplet(int arr[], int size, int x) 
{
	for (int i = 0; i < size - 1; i++)
	{
		unordered_set<int> s;
		for (int j = i + 1; j < size; j++)
		{
			int sum = x- (arr[i] + arr[j]);
			if (s.find(sum) != s.end())
				print_ele(sum, arr[i], arr[j]);
			else
				s.insert(arr[j]);
		}
	}
}


int main()
{

	int arr[7] = { 1, 2, 3, 4, 5, 6, 7 };
	FindTriplet(arr, 7, 12);
    return 0;
}

