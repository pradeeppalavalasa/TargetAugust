#pragma once
#include<string>
using namespace std;

class Beverage
{
private:
	const string m_strDescription;
	double m_price;

public:
	virtual double getPrice() = 0;
	virtual string getDescription() = 0;
};
