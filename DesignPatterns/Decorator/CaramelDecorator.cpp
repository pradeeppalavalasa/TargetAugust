#include "stdafx.h"
#include"CaramelDecorator.h"

string CaramelDecorator::getDescription()
{
	return this->beverageComponent->getDescription() +"Caramel is decorated";
}

double CaramelDecorator::getPrice()
{
	return this->beverageComponent->getPrice() + 10;
}