// CollectingBalls.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<algorithm>
using namespace std;


bool isValid(long long num, long long k)
{
	long long tempnum = num;
	bool isplayer1 = true;
	long long count = 0;
	while (num > 0)
	{
		if (isplayer1)
		{
			count += min(k,num);
			num -= min(k, num);
			isplayer1 = false;
		}
		else
		{
			num -= num/10;
			isplayer1 = true;;
		}
	}

	return count >= ((tempnum + 1) / 2);
}

long long binarysearch(long long num)
{
	long long low = 1;
	long long high = num;
	long long ans;
	while (low <= high)
	{
		long long mid = (low + high) / 2;
		if (isValid(num, mid))
		{
			ans = mid;
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}
	return ans;
}

int main()
{

	long long num;
	cin >> num;
	isValid(43, 1);
	cout << binarysearch(num);
    return 0;
}

