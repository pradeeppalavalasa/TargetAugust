// SingleNumberIII.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<vector>
#include<iostream>
using namespace std;

int firstsetbit(int num)
{
	int firstsetbit = 0;
	while (num != 0)
	{
		firstsetbit++;
		if (num & 1)
			return firstsetbit;
		num = num >> 1;
	}
	return -1;
}

vector<int> singleNumber(vector<int>& nums) {
	int size = nums.size();
	int twonum = 0;
	for (int numcounter = 0; numcounter < size; numcounter++)
	{
		twonum = twonum^nums[numcounter];
	}

	int setbit = firstsetbit(twonum);

	vector<int> ans;
	ans.push_back(0);
	ans.push_back(0);
	for (int numcounter = 0; numcounter < size; numcounter++)
	{
		if (nums[numcounter] & (1 << 1))
			ans[0] = ans[0] ^ nums[numcounter];
		else
			ans[1] = ans[1] ^ nums[numcounter];
	}

	return ans;
}

int main()
{
	vector<int> vec{ -1638685546,-1638685546,
		-2084083624,-2084083624,
		-307525016,-307525016,
		-930251592,-930251592,
		1354460680,1354460680,
		623522045,623522045,
		-1370026032,-1370026032,
		472570145,472570145,
		1145305475,1145305475,
		1122167217,1122167217,
		1063150409,160988123 };
	int test = 160988123 ^ 1063150409;
	vector<int> temp = singleNumber(vec);

    return 0;
}

