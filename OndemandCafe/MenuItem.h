#ifndef OOP_PROJECT_MENUITEM_H
#define OOP_PROJECT_MENUITEM_H

#include <string>
#include "Recipe.h"

using namespace std;

class MenuItem {
private:
	string m_nameOfCoffee;
	int price;

public:

	void setCoffeeName(const Recipe &coffeRecipe);
	void setCoffeePrice(const Recipe &coffeeRecipe);
	string getCoffeeName() const;
};


#endif //OOP_PROJECT_MENUITEM_H