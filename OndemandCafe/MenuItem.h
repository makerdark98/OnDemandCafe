#pragma once

#include <string>
#include "Recipe.h"

using namespace std;

class MenuItem {
private:
	Recipe m_recipe;

public:
	MenuItem(const string& nameOfCoffee, const Recipe &coffeeRecipe);
	const Recipe& getRecipe() const;
	Recipe& getRecipe();
	
};
