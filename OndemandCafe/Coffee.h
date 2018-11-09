#pragma once

#include "Recipe.h"

class Coffee
{
private:
	Recipe m_recipe;
public:
	Coffee(const Recipe& recipe);
	~Coffee();
	string getName();
	const Recipe getRecipe() const;

};

