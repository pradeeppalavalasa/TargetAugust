// LongestNonRepeatingSubStr.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <iostream>

using namespace std;

bool checkAlpha(int alpha[26])
{
	for (int j = 0; j < 26; j++)
	{
		if (alpha[j] > 1)
			return false;
	}
	return true;
}

bool valid(string s, int n)
{
	int alpha[26] = { 0 };

	for (int i = 0; i<n; i++)
	{
		alpha[s[i] - 'a']++;	
	}

	if (checkAlpha(alpha))
		return true;


	for (int i = n; i<s.length(); i++)
	{
		alpha[s[i - n] - 'a']--;
		alpha[s[i] - 'a']++;

		if (checkAlpha(alpha))
			return true;
		
	}
	return false;
}


int lengthOfLongestSubstring(string s) {
	int low = 0;
	int high = s.length();
	int mid = 0;
	int ans = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;

		if (valid(s, mid))
		{
			ans = mid;
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
	return ans;
}

int main()
{
	std::cout << lengthOfLongestSubstring("abcabcbb");
	getchar();
    return 0;
}

