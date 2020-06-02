// FindDifference.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<string>
using namespace std;

char findTheDifference2(string s, string t) {
	for (int i = 0; i < s.length(); i++) {
		t[t.length() - 1] ^= s[i] ^ t[i];
	}
	return t[t.length() - 1];
}

char findTheDifference1(string s, string t) {

	int sumOfS = 0;
	for (int i = 0; i < s.length(); i++) {
		sumOfS += s[i];
	}

	int sumOfT = 0;
	for (int i = 0; i < t.length(); i++) {
		sumOfT += t[i];
	}

	return (char)(sumOfT - sumOfS);
}

char findTheDifference(string s, string t) {

	int temp[26] = { 0 };

	for (int i = 0; i<s.size(); i++)
	{
		temp[s[i] - 'a']++;
		temp[t[i] - 'a']--;
	}

	temp[t[s.size()] - 'a']--;

	for (int i = 0; i<26; i++)
	{
		if (temp[i] != 0)
			return char(i + 'a');
	}
	return '-';
}

int main()
{	
	char ans = findTheDifference2("abcd", "abcde");
    return 0;
}

