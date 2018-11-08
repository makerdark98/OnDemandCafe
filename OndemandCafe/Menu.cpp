#include "Menu.h"

Menu::Menu(const vector<MenuItem> &menuList) {
	m_menuList = menuList;
}

void Menu::addMenuItem(const MenuItem& menuName) {
	m_menuList.push_back(menuName);
}

void Menu::deleteMenuItem(const vector<MenuItem> &menuList,const MenuItem& menuName) {

	for (auto i : menuList) {
		if (i.getCoffeeName() == menuName.getCoffeeName()) {
			//menuList.erase(menuName); 아직 잘 모르겠어서 생각하는 중..
		}
	}

}

vector<MenuItem> Menu::getMenuItem() const {
	return m_menuList;
}