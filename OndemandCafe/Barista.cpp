#include"Barista.h"

Barista::Barista()
{
}

Barista::~Barista()
{
}

Coffee Barista::makeCoffee(const Recipe& recipe) {
	Coffee coffee(recipe);
	return coffee;
}