// BoundarySum.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
using namespace std;
#include<vector>



int allIndexes(int input[], int size, int x, vector<int> &output) {
	/* Don't write main().
	Don't read input, it is passed as function argument.
	Save all the indexes in the output array passed and return the size of output array.
	Taking input and printing output is handled automatically.
	*/
	if (size == 0)
		return 0;

	int size_array = allIndexes(input + 1, size - 1, x, output);

	for (int i = 0; i<size_array; i++)
	{
		output[i]++;
	}

	if (input[0] == x)
	{
		output.push_back(0);
		for (int i = 0; i<size_array; i++)
		{
			output[i + 1] = output[i];
		}
		output[0]=0;
		
		return size_array + 1;
	}


	return size_array;
}


int lastIndex(int input[], int size, int x) {
	if (size == 0)
		return -1;


	int ans = lastIndex(input + 1, size - 1, x);

	if (ans != -1)
		return ans + 1;

	if (input[0] == x)
		return 0;
	return -1;

}


int marbles()
{
	int n, target;
	cin >> n;
	cin >> target;
	int* input = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> input[i];
	}

	int sum = 0;
	int left_counter = 0;
	vector<int> vect;
	for (int i = 0; i < n; i++)
	{
		
		if (sum > target)
		{
			vect.erase(vect.begin());
			sum -= input[left_counter++];
			i--;
		}
		else if(sum < target){
			vect.push_back(input[i]);
			sum += input[i];
		}

		if (sum == target)
		{
			for (int i = 0; i<vect.size(); i++)
				cout << vect[i] << " ";

			cout << endl;
			cout << "true" << endl;

			return 0;
		}

	}


	cout << "false" << endl;
	return 0;
}

int cricket()
{
	int n;
	cin >> n;
	int* input = new int[n];
	for (int i = 0; i<n; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i<=(n - 1) / 2; i++)
	{
		cout << ((input[i] + input[n - 1 - i]) / 10) << " " << ((input[i] + input[n - 1 - i]) % 10) << endl;
	}
	return 0;
}

int totalSum()
{
	//Write your code here
	int testcases;
	cin >> testcases;
	while (testcases-- != 0)
	{
		int n;
		cin >> n;
		int** input=new int*[n];
		for (int i = 0; i<n; i++)
		{
			input[i] = new int[n];
		}

		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
			{
				int test;
				cin >> test;
				input[i][j]= test;
			}
		}

		int sum = 0;
		for (int i = 1; i<n-1; i++)
		{
			sum += input[0][i] + input[i][0] + input[n - 1][i] + input[i][n - 1];
		}

		for (int i = 0; i<n; i++)
		{
			sum += input[i][i] + input[i][n - i - 1];
		}

		if (n % 2 == 1)
			sum -= input[n / 2][n / 2];
		cout << sum << endl;

	}

	return 0;
}
 
int main()
{
	int a[11] = { 21, 22, 46, 12, 61, 25, 33, 16, 99, 96, 25 };
	vector<int> vec;
	cout<<allIndexes(a, 11, 25, vec);
	return 0;
}

