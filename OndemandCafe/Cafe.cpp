#include "Cafe.h"

Cafe::Cafe()
	:m_menu(vector<MenuItem>())
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
