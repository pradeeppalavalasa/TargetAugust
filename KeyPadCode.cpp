// KeyPadCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<map>
#include<string>
using namespace std;

map<int, string> KEYCODE = { { 2, "abc" },{ 3, "def" },{ 4, "ghi" },{ 5, "jkl" },
{ 6, "mno" },{ 7, "pqrs" },{ 8, "tuv" },{ 9, "wxyz" } };

void keypadCombinations(int num, string output)
{
	if(num == 0)
	{
		cout << output<<endl;
		return;
	}

	int numCode = num % 10;
	for (int i=0;i<KEYCODE[numCode].size();i++)
	{
		keypadCombinations(num / 10, output + KEYCODE[numCode][i]);
	}
}

int keypad(int num, string output[]) {

	if (num == 0||num==1)
	{
		output[0] = "";
		return 1;
	}

	int smallstringsize = keypad(num / 10, output);
	int numcode = num % 10;
	for (int i = 0; i < KEYCODE[numcode].size()-1; i++)
	{
		for (int j = 0; j < smallstringsize; j++)
		{
			output[(i+1)*smallstringsize  + j] = output[j];
		}
	}

	int newsize = smallstringsize * KEYCODE[numcode].size();

	for (int i = 0; i < KEYCODE[numcode].size(); i++)
	{
		for (int j = 0; j < smallstringsize; j++)
		{
			output[i*smallstringsize +j] += KEYCODE[numcode][i];
		}
	}

	return newsize;

}


int main()
{

	string ans;
	keypadCombinations(23, ans);

    return 0;
}

