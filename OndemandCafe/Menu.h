#pragma once

#include <vector>
#include "Recipe.h"

using namespace std;
class Menu
{
private:
	vector<Recipe>m_menuList;
public:
	Menu(const vector<Recipe> &menuList);
	void addMenuItem(const Recipe &menuName);
	void deleteMenuItem(const string& menuName);
	void modifyMenuName(const string& originName, const string& newName);
	vector<Recipe> getMenuItem() const;
	vector<Recipe>::const_iterator begin() const;
	vector<Recipe>::const_iterator end() const;
};
