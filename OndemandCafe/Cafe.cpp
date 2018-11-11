#include "Cafe.h"

Cafe::Cafe(const Menu& menu)
	:m_menu(menu)
{
	
}

Cafe::~Cafe()
{
}

const Menu & Cafe::getMenu() const
{
	return m_menu;
}

Coffee Cafe::orderMenu(const unsigned int& orderNumber) const
{
	return m_Barista.makeCoffee(m_menu[orderNumber]);
}

Coffee Cafe::orderCustom(vector<pair<Ingredient*, Amount>> customOrderList) const
{
	return Coffee(Recipe(vector<RecipeData>()));
}
