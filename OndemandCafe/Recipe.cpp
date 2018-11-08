#include "Recipe.h"



Recipe::Recipe(const vector<pair<Ingredient *, Amount>>& recipeData) {
	m_recipeData = recipeData;
}

void Recipe::setCoffeeName(const string m_nameOfCoffee) {
	this->m_nameOfCoffee = m_nameOfCoffee;
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

int Recipe::priceCalculate(const vector<pair<Ingredient *, Amount>>& recipeData) {
	int retPrice = 0;
	for (auto i : recipeData) {
		retPrice += getUnitPrice(i.first)*(i.second);
	}
	return retPrice;
}


