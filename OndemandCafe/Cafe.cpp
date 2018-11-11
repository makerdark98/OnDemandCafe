#include "Cafe.h"

Cafe::Cafe(const Menu& menu, const IngredientList& ingredients)
	:m_menu(menu),
	m_ingredients(ingredients)
{
	
}

Cafe::~Cafe()
{
}

const Menu & Cafe::getMenu() const
{
	return m_menu;
}

const IngredientList & Cafe::getIngredientList() const
{
	return m_ingredients;
}

Coffee Cafe::orderMenu(const unsigned int& orderNumber) const
{
	return m_Barista.makeCoffee(m_menu[orderNumber]);
}

Coffee Cafe::orderCustom(const Recipe& recipe) const
{
	Coffee coffee = m_Barista.makeCoffee(recipe);
	for (const auto& item : m_menu) {
		if (coffee == item) {
			coffee.setName(item.getCoffeeName());
		}
	}
	return coffee;
}
