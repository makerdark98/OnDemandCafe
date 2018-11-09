#pragma once

#include <vector>
#include "MenuItem.h"

using namespace std;
class Menu
{
private:
	vector<MenuItem>m_menuList;
public:
	Menu(const vector<MenuItem> &menuList);
	void addMenuItem(const MenuItem &menuName);
	void deleteMenuItem(const MenuItem &menuName);
	void modifyMenuName(const string& originName, const string& newName);
	vector<MenuItem> getMenuItem() const;
	
};

