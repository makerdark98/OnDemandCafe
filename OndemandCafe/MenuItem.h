#pragma once

#include <string>
#include "Recipe.h"

using namespace std;

class MenuItem {
private:
	string m_nameOfCoffee;
	int m_price;

public:

	void setCoffeeName(const Recipe &coffeRecipe);
	void setCoffeePrice(const Recipe &coffeeRecipe);
	string getCoffeeName() const;
	int getCoffeePrice() const;
};
