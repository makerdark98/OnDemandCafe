#include "Menu.h"

Menu::Menu(const vector<Recipe> &menuList) {
	m_menuList = menuList;
}
void Menu::addMenuItem(const Recipe& menuName) {
	m_menuList.push_back(menuName);
}

void Menu::deleteMenuItem(const string& menuName){
	
	for (auto iterMenu = m_menuList.begin(); iterMenu < m_menuList.end(); iterMenu++) {
		if (iterMenu->getCoffeeName() == menuName) {
			m_menuList.erase(iterMenu);
			break;
		}
	}
}

void Menu::modifyMenuName(const string & originName, const string & newName){
	for (auto recipe : m_menuList) {
		if (recipe.getCoffeeName() == originName) {
			recipe.setCoffeeName(newName);
			break;
		}
	}
}

vector<Recipe> Menu::getMenuItem() const {
	return m_menuList;
}


const Recipe & Menu::operator[](unsigned int idx) const
{
	return m_menuList[idx];
}

vector<Recipe>::const_iterator Menu::begin() const
{
	return m_menuList.begin();
}

vector<Recipe>::const_iterator Menu::end() const
{
	return m_menuList.end();
}

size_t Menu::size() const
{
	return m_menuList.size();
}
