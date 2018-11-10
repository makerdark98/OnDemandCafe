#pragma once

#include "Recipe.h"
using namespace std;

class Coffee
{
private:
	Recipe m_recipe;
public:
	Coffee(const Recipe& recipe);
	~Coffee();
	const string getName()const;
	const int getPrice() const;
	const Recipe getRecipe() const;
};

