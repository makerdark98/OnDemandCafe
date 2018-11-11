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

const Bill Cafe::orderMenu() const
{
	return Bill(vector<Coffee>());
}

const Bill Cafe::orderCustom(vector<pair<Ingredient*, Amount>> customOrderList) const
{
	return Bill(vector<Coffee>());
}
