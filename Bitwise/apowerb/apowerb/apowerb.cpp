// apowerb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string> 
#include <algorithm>
using namespace std;


int main() {
	int testcases;
	cin >> testcases;

	while (testcases-- != 0)
	{
		string rawInput;
		vector<string> numbers;
		while (std::getline(cin, rawInput, ' '))
		{
			numbers.push_back(rawInput);
		}
	}

	return 0;
}


