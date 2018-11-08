#pragma once

#ifndef OOP_PROJECT_MENU_H
#define OOP_PROJECT_MENU_H

#include <vector>
#include "MenuItem.h"

using namespace std;
class Menu
{
private:
	vector<MenuItem>m_menuList;
public:
	Menu();
	~Menu();
};

#endif // !OOP_PROJECT_MENU_H
