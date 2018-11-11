#pragma once

#include "Barista.h"
#include "Menu.h"
#include "Bill.h"
#include "IngredientList.h"

class Cafe {
protected:
	Menu m_menu;
	Barista m_Barista;
	IngredientList m_ingredients;
public:
	Cafe(const Menu& menu, const IngredientList& ingredients);
	virtual ~Cafe();
	const Menu& getMenu() const;
	const IngredientList& getIngredientList() const;
	Coffee orderMenu(const unsigned int& orderNumber) const;
	Coffee orderCustom(const Recipe& customOrderList) const;
};