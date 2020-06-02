// Powerof4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"



bool isPowerOfFour(int num) {
	if (num <= 0 || (num & (num - 1)))
		return false;

	int setbitpos = 0;

	while (num != 1 && num != 0)
	{
		setbitpos++;
		num = num >> 1;
	}

	return setbitpos % 2 == 0;
}


int main()
{
	bool val = isPowerOfFour(4);
    return 0;
}

