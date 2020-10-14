// DifferentNames.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
#include <map> 
#include <string> 
#include <sstream>
#include<algorithm>
#include<vector>

//int max_chairs_needed(int *start, int *end, int n)
//{
//	int i = 1, j = 0;
//	int max_chairs = 1, ans = 0;
//
//	while (i < n && j < n)
//	{
//		if (start[i] <= end[j])
//		{
//			max_chairs++;
//			i++;
//		}
//		else if (start[i] > end[j])
//		{
//			max_chairs--;
//			j++;
//		}
//
//		if (ans < max_chairs)
//			ans = max_chairs;
//	}
//	return ans;
//}
//
//
//int main() {
//	int customers;
//	cin >> customers;
//	int *start = new int[customers];
//	int *end = new int[customers];
//
//	for (int i = 0; i<customers; i++)
//	{
//		cin >> start[i];
//	}
//
//	for (int i = 0; i<customers; i++)
//	{
//		cin >> end[i];
//	}
//
//	sort(start, start + customers);
//	sort(end, end + customers);
//
//	cout << max_chairs_needed(start, end, customers);
//
//	return 0;
//}
//
char* uniqueChar(char *str) {
	// Write your code here
	string s=str;

	int count_lower[255] = { 0 };

	int i = 0;
	while (s[i] != '\0')
	{
		count_lower[s[i]]++;
		i++;
	}

	i = 0;
	while (s[i] != '\0')
	{
		if (count_lower[s[i]] >= 1)
		{
			cout << s[i];
			count_lower[s[i]] = 0;
		}
		

		i++;
	}
	return NULL;

}

bool comparator(pair<string, int> p1, pair<string, int> p2)
{
	if (p1.second > p2.second)
		return true;
	else if (p1.second < p2.second)
		return false;
	else
		return p1.first < p2.first;
}


int main()
{
	int students;
	cin >> students;
	vector< pair <string, int> > names;

	students++;
	while (students-- != 0)
	{
		string nameslist;
		getline(cin, nameslist);
		stringstream ss(nameslist); // Turn the string into a stream. 
		string s;

		int i = 0;
		int marks=0;
		string str;
		while (getline(ss, s, ' '))
		{
			if (i == 0)
				str = s;
			else
				marks += stoi(s);

			i++;
		}

		if(!str.empty())
			names.push_back(make_pair(str, marks));
	}
	
	sort(names.begin(), names.end(), comparator);



	for (int i = 0; i<names.size(); i++)
	{
		if(!names[i].first.empty())
			cout <<i+1 <<" "<< names[i].first <<endl;

	}

	

	
    return 0;
}

