// MajorityElement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include <iostream> 
using namespace std;

int majorityElement(vector<int>& nums) 
{
	int majority_element = nums[0];
	int majority_counter = 1;
	int size = nums.size();
	for (int numcounter = 1; numcounter<size; numcounter++)
	{
		if (majority_element == nums[numcounter])
			majority_counter++;
		else
		{
			if (majority_counter == 0)
			{
				majority_element = nums[numcounter];
				majority_counter = 1;
			}
			else
				majority_counter--;	
		}
	}

	majority_counter = 0;
	for (int numcounter = 0; numcounter<size; numcounter++)
	{
		if (nums[numcounter] == majority_element)
			majority_counter++;
	}

	if (majority_counter >= size / 2)
		return majority_element;
	else
		return -1;
}
int main()
{
	vector<int> vec{ 2,2,1,1,1,2,2 };
	cout << majorityElement(vec);
	getchar();
    return 0;
}

