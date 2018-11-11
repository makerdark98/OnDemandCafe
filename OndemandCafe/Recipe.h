#pragma once

using Amount = int;

#include <string>
#include <vector>
#include <utility>
#include "Ingredient.h"


using namespace std;
class RecipeData {
private:
	shared_ptr<Ingredient> m_ingredient;
	shared_ptr<Amount> m_amount;
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
	
	Recipe(const string& nameOfCoffee, const vector<RecipeData>& recipeData);
	Recipe(const vector<RecipeData>& recipeData);
	string getCoffeeName() const;
	void setCoffeeName(const string& m_nameOfCoffee);

	int getCoffeePrice() const;
	Recipe append(const RecipeData& newIngredient)const;
	Recipe operator+(const RecipeData& newIngredient)const;
	bool operator==(const Recipe& recipeData);
	const bool equals(const Recipe& recipeData)const;


};
