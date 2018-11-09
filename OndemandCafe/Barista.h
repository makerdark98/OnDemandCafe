#pragma once
#include<string>
#include<vector>
#include<utility>
#include "Coffee.h"
class Barista
{
public:
	Coffee makeCoffee(const Recipe& recipe);
	Barista();
	~Barista();
};

