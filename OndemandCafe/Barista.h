#pragma once
#include "Recipe.h"
#include "Coffee.h"
class Barista
{
public:
	Coffee makeCoffee(const Recipe& recipe);
	Barista();
	~Barista();
};

