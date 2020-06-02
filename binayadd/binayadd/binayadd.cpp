// binayadd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


int getSum(int x, int y) {
	while (y != 0) {
		// carry contains common set bits of x and y
		int carry = x & y;
		// Sum of bits of x and y where at least one of the bits is not set
		x = x ^ y;
		// Carry is shifted by one so that adding it to x gives the required sum
		y = (unsigned int)carry << 1;
	}
	return x;
}


int main()
{
	int ans = getSum(-3, 2);
    return 0;
}

