#pragma once

#include <string>
#include "Recipe.h"

using namespace std;

class MenuItem {
private:
	string m_nameOfCoffee;
	Recipe m_coffeeRecipe;

public:
	MenuItem(const string& nameOfCoffee, const Recipe &coffeeRecipe);
	void setCoffeeName(const string& newName);
	string getCoffeeName() const;
};
