#include"Barista.h"

Barista::Barista()
{
}

Barista::~Barista()
{
}

Coffee Barista::makeCoffee(const Recipe& recipe) const{
	Coffee coffee(recipe);
	return coffee;
}