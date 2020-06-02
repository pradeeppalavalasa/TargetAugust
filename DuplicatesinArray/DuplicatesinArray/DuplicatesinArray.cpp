// DuplicatesinArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
	int N = nums.size();
	vector<int> ans;
	for (int i = 0; i<N; i++)
	{
		int index = (nums[i] % (N+1)) - 1;
		nums[index] += (N + 1);

		if (nums[index] / (N + 1) == 2)
			ans.push_back(index + 1);
	}

	return ans;
}


int main()
{
	vector<int> vec = { 10,2,5,10,9,1,1,4,3,7 };
	vector<int> ans = findDuplicates(vec);
    return 0;
}

