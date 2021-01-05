#include "stdafx.h"
#include"SoyDecorator.h"

string SoyDecorator::getDescription()
{
	return this->beverageComponent->getDescription() + "Soy is decorated";
}

double SoyDecorator::getPrice()
{
	return this->beverageComponent->getPrice() + 20;
}