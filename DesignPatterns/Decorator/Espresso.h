#pragma once
#include"Beverage.h"
#include<string>
using namespace std;

class Espresso: public Beverage
{
public:
	Espresso()
	{
	}

private:
	string m_strDescription;
	double m_price;

public:
	double getPrice();
	string getDescription();
};
