// LightUpBulbs.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//int main()
//{
//	int n, x, y;
//	cin >> n >> x >> y;
//	string str;
//	cin >> str;
//
//	int zerogroups = (str[0] == '0') ? 1 : 0;
//	for (int i = 0; i<n - 1; i++)
//	{
//		if (str[i] == '1' && str[i + 1] == '0')
//			zerogroups++;
//
//	}
//	if (zerogroups)
//		cout << (zerogroups - 1)*min(x, y) + y;
//	else
//		cout << 0;
//	return 0;
//}

int main() {

	// Write your code here

	int n;
	cin >> n;
	int *arr = new int[n];

	for (int i = 0; i<n; i++)
		cin >> arr[i];

	int swaps = 0;
	for (int i = 0; i <n; i++)
	{
		if (abs(i+1 - arr[i])>2)
		{
			cout << "NO";
			return 0;
		}

		else
			swaps += abs(i+1 - arr[i]);

	}
	cout << "YES" << endl;
	cout << swaps / 2 << endl;
	return 0;

}


