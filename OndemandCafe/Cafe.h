#pragma once

#include "Barista.h"
#include "Menu.h"
#include "Bill.h"

class Cafe {
protected:
	Menu m_menu;
	Barista m_Barista;
public:
	const Menu& getMenu() const;
	const Bill orderMenu() const;
	const Bill orderCustom(vector<pair<Ingredient*, Amount> > customOrderList) const;
};