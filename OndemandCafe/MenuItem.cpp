#include "MenuItem.h"


MenuItem::MenuItem(const string& nameOfCoffee, const Recipe &coffeeRecipe) :m_recipe(coffeeRecipe) {
}

const Recipe& MenuItem::getRecipe() const
{
	return m_recipe;
}

Recipe & MenuItem::getRecipe()
{
	return m_recipe;
}
