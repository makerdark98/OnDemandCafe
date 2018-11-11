#include "Recipe.h"


Recipe::Recipe(const vector<RecipeData>& recipeData) {
	m_recipeData = recipeData;
}

void Recipe::setCoffeeName(const string& m_nameOfCoffee) {
	this->m_nameOfCoffee = m_nameOfCoffee;
}

string Recipe::getCoffeeName() const {
	return m_nameOfCoffee;
}

int Recipe::getCoffeePrice() const {
	int retPrice=0;

	for (const auto& i : m_recipeData) {
		retPrice = i.getPrice();
	}
	return retPrice;
}

Recipe Recipe::append(const RecipeData& newIngredient)const {
	Recipe result = *this;
	result.m_recipeData.push_back(newIngredient);
	return result;
}

Recipe Recipe::operator+(const RecipeData& newIngredient)const {
	Recipe result = *this;
	result.append(newIngredient);
	return result;
}

bool Recipe::operator==(const Recipe& recipeData) {
	return true; // TODO: to implement
}

const bool Recipe::equals(const Recipe& recipeData) const {
	return true; // TODO: to implement
}

RecipeData::RecipeData(const Ingredient & ingredient, const Amount & amount)
{
	m_ingredient = new Ingredient(ingredient);
	m_amount = new Amount(amount);
	
}

RecipeData::~RecipeData()
{
	if (m_ingredient != nullptr)
		delete m_ingredient;
	if (m_amount != nullptr)
		delete m_amount;
}

const Price RecipeData::getPrice() const
{
	return *m_amount * m_ingredient->getUnitPrice();
}
