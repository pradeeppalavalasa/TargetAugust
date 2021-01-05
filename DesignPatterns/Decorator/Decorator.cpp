// Decorator.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"Espresso.h"
#include"CaramelDecorator.h"
#include"SoyDecorator.h"


int main()
{
	Beverage* pEspressoWithSoy = new SoyDecorator(new Espresso());
	cout << pEspressoWithSoy->getDescription() << "  " << pEspressoWithSoy->getPrice();

    return 0;
}

