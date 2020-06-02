// NumberDissappered.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include <cmath>
using namespace std;


vector<int> findDisappearedNumbers(vector<int>& nums) 
{
	for (int numcounter = 0; numcounter < nums.size(); numcounter++)
	{
		int index = abs(nums[numcounter]) - 1;
		if (nums[index] > 0)
			nums[index] = -nums[index];
	}

	vector<int> ans;
	for (int numcounter = 0; numcounter < nums.size(); numcounter++)
	{
		if (nums[numcounter] > 0)
			ans.push_back(numcounter+1);
	}

	return ans;
}


int main()
{
	vector<int> nums = { 4,3,2,7,8,2,3,1 };
	vector<int> ans = findDisappearedNumbers(nums);
    return 0;
}

