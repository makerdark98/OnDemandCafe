#include "Recipe.h"


Recipe::Recipe(const string & nameOfCoffee, const vector<RecipeData>& recipeData)
	:m_nameOfCoffee(nameOfCoffee), m_recipeData(recipeData)
{
	
}

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
	m_ingredient = make_shared<Ingredient>(ingredient);
	m_amount = make_shared<Amount>(amount);
}

RecipeData::~RecipeData()
{
}

const Price RecipeData::getPrice() const
{
	return *m_amount * m_ingredient->getUnitPrice();
}
