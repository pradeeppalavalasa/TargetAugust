#pragma once
#include"Beverage.h"
#include<string>
using namespace std;

class CaramelDecorator : public Beverage
{
public:
	CaramelDecorator(Beverage* beverage)
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
