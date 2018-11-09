#include "Menu.h"

Menu::Menu(const vector<MenuItem> &menuList) {
	m_menuList = menuList;
}
void Menu::addMenuItem(const MenuItem& menuName) {
	m_menuList.push_back(menuName);
}

void Menu::deleteMenuItem(const MenuItem & menuName){
	
	for (auto iterMenu = m_menuList.begin(); iterMenu < m_menuList.end(); iterMenu++) {
		if (iterMenu->getCoffeeName() == menuName.getCoffeeName()) {
			
		}
	}


}

void Menu::modifyMenuName(const string & originName, const string & newName){

	for (auto iterMenu = m_menuList.begin(); iterMenu < m_menuList.end(); iterMenu++) {
		if (iterMenu->getCoffeeName() == originName) {
			iterMenu->setCoffeeName(newName);
			break;
		}
	}
}

vector<MenuItem> Menu::getMenuItem() const {
	return m_menuList;
}