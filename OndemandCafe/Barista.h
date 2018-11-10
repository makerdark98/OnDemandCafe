#pragma once
#include "Recipe.h"
#include "Coffee.h"
using namespace std;

class Barista
{
public:
	Coffee makeCoffee(const Recipe& recipe);
	Barista();
	~Barista();
};

