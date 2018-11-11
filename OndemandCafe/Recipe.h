#pragma once

using Amount = int;

#include <string>
#include <vector>
#include <utility>
#include "Ingredient.h"


using namespace std;
class RecipeData {
private:
	Ingredient* m_ingredient;
	Amount* m_amount;
public:
	RecipeData(const Ingredient& ingredient, const Amount& amount);
	virtual ~RecipeData();

	const Price getPrice() const;

};

class Recipe{
private:
	string m_nameOfCoffee;
	vector< RecipeData >m_recipeData;
public:
	
	Recipe(const vector<RecipeData>& recipeData);
	string getCoffeeName() const;
	void setCoffeeName(const string& m_nameOfCoffee);

	int getCoffeePrice() const;
	Recipe append(const RecipeData& newIngredient)const;
	Recipe operator+(const RecipeData& newIngredient)const;
	bool operator==(const Recipe& recipeData);
	const bool equals(const Recipe& recipeData)const;


};
