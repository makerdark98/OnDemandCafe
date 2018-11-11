#pragma once

#include "Barista.h"
#include "Menu.h"
#include "Bill.h"

class Cafe {
protected:
	Menu m_menu;
	Barista m_Barista;
public:
	Cafe(const Menu& menu);
	virtual ~Cafe();
	const Menu& getMenu() const;
	Coffee orderMenu(const unsigned int& orderNumber) const;
	Coffee orderCustom(vector<pair<Ingredient*, Amount> > customOrderList) const;
};