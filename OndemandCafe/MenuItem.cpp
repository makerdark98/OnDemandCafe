#include "MenuItem.h"

void MenuItem::setCoffeeName(const Recipe &coffeeRecipe) {
	m_nameOfCoffee = coffeeRecipe.getCoffeeName();
}

void MenuItem::setCoffeePrice(const Recipe &coffeeRecipe) {
	m_price = coffeeRecipe.getCoffeePrice();
}

string MenuItem::getCoffeeName()const {
	return m_nameOfCoffee;
}