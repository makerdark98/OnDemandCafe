#include "Recipe.h"


Recipe::Recipe(const vector<pair<Ingredient *, Amount>>& recipeData) {
	m_recipeData = recipeData;
}

void Recipe::setCoffeeName(const string m_nameOfCoffee) {
	this->m_nameOfCoffee = m_nameOfCoffee;
}

string Recipe::getCoffeeName() const {
	return m_nameOfCoffee;
}

int Recipe::getCoffeePrice() const {
	return price;
}

Recipe Recipe::append(const pair<Ingredient *, Amount>& newIngredient)const {
	Recipe result = *this;
	result.m_recipeData.push_back(newIngredient);
	return result;
}

Recipe Recipe::operator+(const pair<Ingredient *, Amount>& newIngredient)const {
	Recipe result = *this;
	result.append(newIngredient);
	return result;
}

bool Recipe::operator==(const Recipe& recipeData) {


}

const bool Recipe::equals(const Recipe& recipeData) const {



}

void Recipe::priceCalculate(const vector<pair<Ingredient *, Amount>>& recipeData) {
	price = 0;
	for (auto i : recipeData) {
		 price+= getUnitPrice(i.first)*(i.second);
	}
}


