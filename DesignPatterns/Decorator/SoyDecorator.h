#pragma once
#include"Beverage.h"
#include<string>
using namespace std;

class SoyDecorator : public Beverage
{
public:
	SoyDecorator(Beverage* beverage)
	{
		beverageComponent = beverage;
	}

private:
	string m_strDescription;
	double m_price;
	Beverage* beverageComponent;

public:
	double getPrice();
	string getDescription();
};

