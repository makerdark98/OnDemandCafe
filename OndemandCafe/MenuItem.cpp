#include "MenuItem.h"


MenuItem::MenuItem(const string& nameOfCoffee, const Recipe &coffeeRecipe) :m_coffeeRecipe(coffeeRecipe) {
	m_nameOfCoffee = nameOfCoffee;
}

string MenuItem::getCoffeeName()const {
	return m_nameOfCoffee;
}
void MenuItem::setCoffeeName(const string& newName) {
	// TODO : to implement
}
