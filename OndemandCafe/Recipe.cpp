#include "Recipe.h"

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

const Ingredient & RecipeData::getIngredient() const
{
	return *m_ingredient;
}

const Amount & RecipeData::getAmount() const
{
	return *m_amount;
}

bool RecipeData::operator==(const RecipeData& recipeData) const
{
	return *m_ingredient == *recipeData.m_ingredient && *m_amount == *recipeData.m_amount;
}


Recipe::Recipe(const vector<RecipeData>& recipeData) {
	m_recipeData = recipeData;
}

Recipe::Recipe(const string & nameOfCoffee, const vector<RecipeData>& recipeData)
	:m_nameOfCoffee(nameOfCoffee), m_recipeData(recipeData)
{
	
}

Recipe::~Recipe()
{
}

string Recipe::getCoffeeName() const {
	return m_nameOfCoffee;
}

void Recipe::setCoffeeName(const string& m_nameOfCoffee) {
	this->m_nameOfCoffee = m_nameOfCoffee;
}

int Recipe::getCoffeePrice() const {
	int retPrice=0;

	for (const auto& i : m_recipeData) {
		retPrice += i.getPrice();
	}
	return retPrice;
}

Recipe& Recipe::append(const RecipeData& newIngredient) {
	m_recipeData.push_back(newIngredient);
	return *this;
}

Recipe& Recipe::append(const vector<RecipeData>& newIngredient) {
	m_recipeData.insert(m_recipeData.end(), newIngredient.begin(), newIngredient.end());
	return *this;
}

const bool Recipe::equals(const Recipe& recipeData) const {
	return m_recipeData == recipeData.m_recipeData; // TODO: to implement
}

Recipe Recipe::add(const RecipeData & newIngredient) const
{
	Recipe result = *this;
	result.m_recipeData.push_back(newIngredient);
	return result;
}

Recipe Recipe::operator+(const RecipeData& newIngredient)const {
	return add(newIngredient);
}

bool Recipe::operator==(const Recipe& recipeData) const{
	return equals(recipeData);
}
