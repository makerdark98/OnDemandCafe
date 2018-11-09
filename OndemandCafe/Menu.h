#pragma once

#include <vector>
#include "MenuItem.h"

using namespace std;
class Menu
{
private:
	vector<MenuItem>m_menuList;
public:
	Menu(const vector<MenuItem> &menuItem);
	void addMenuItem(const MenuItem &menuName);
	void deleteMenuItem(const vector<MenuItem> &menuList,const MenuItem &menuName);
	void modifyMenuItem(const MenuItem& menuName, const string newMenuName);
	vector<MenuItem> getMenuItem() const;

};

#endif // !OOP_PROJECT_MENU_H
