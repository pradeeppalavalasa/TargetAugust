// MonotonicArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool isMonDec(vector<int>& A) {

	for (int i = 0; i<A.size() - 1; i++)
	{
		if (A[i]<A[i + 1])
			return false;
	}
	return true;
}

bool isMonInc(vector<int>& A) {

	for (int i = 0; i<A.size() - 1; i++)
	{
		if (A[i]>A[i + 1])
			return false;
	}
	return true;
}

bool isMonotonic(vector<int>& A) {

	if (A[0]<A[A.size() - 1])
		return isMonInc(A);
	else
		return isMonDec(A);

}

bool isMonotonic2(vector<int>& A) {
{if (A.size() < 2)
		return true;

	int difference = 0;

	for (int i = 1; i < A.size(); i++) {
		int newDifference = A[i] - A[i - 1];
		if (newDifference == 0)
			continue;
		else if (newDifference > 0 && difference < 0)
			return false;
		else if (newDifference < 0 && difference > 0)
			return false;
		difference = newDifference;
	}
	return true;
	
}


int main()
{
    return 0;
}

