#pragma once

#include "Recipe.h"
class Barista
{
public:
	Coffee makeCoffee(const Recipe& recipe);
	Barista();
	~Barista();
};

