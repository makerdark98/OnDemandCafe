#include "Menu.h"

Menu::Menu(const vector<MenuItem> &menuList) {
	m_menuList = menuList;
}
void Menu::addMenuItem(const MenuItem& menuName) {
	m_menuList.push_back(menuName);
}

void Menu::deleteMenuItem(const string& menuName){
	
	for (auto iterMenu = m_menuList.begin(); iterMenu < m_menuList.end(); iterMenu++) {
		if (iterMenu->getRecipe().getCoffeeName() == menuName) {
			m_menuList.erase(iterMenu);
			break;
		}
	}
}

void Menu::modifyMenuName(const string & originName, const string & newName){
	for (auto item : m_menuList) {
		Recipe& recipe = item.getRecipe();
		if (recipe.getCoffeeName() == originName) {
			recipe.setCoffeeName(newName);
			break;
		}
	}
}

vector<MenuItem> Menu::getMenuItem() const {
	return m_menuList;
}

vector<MenuItem>::const_iterator Menu::begin() const
{
	return m_menuList.begin();
}

vector<MenuItem>::const_iterator Menu::end() const
{
	return m_menuList.end();
}
