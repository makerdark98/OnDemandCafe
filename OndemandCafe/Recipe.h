#pragma once

#ifndef OOP_PROJECT_RECIPE_H
#define OOP_PROJECT_RECIPE_H

typedef double Amount;

#include <string>
#include <vector>
#include <utility>
#include "Ingredient.h"


using namespace std;

class Recipe{
private:
	string m_nameOfCoffee;
	vector< pair<Ingredient *, Amount>>m_recipeData;
	int price;
public:
	
	Recipe(const vector<pair<Ingredient *, Amount>>& recipeData);
	void setCoffeeName(const string m_nameOfCoffee);
	string getCoffeeName() const;
	int getCoffeePrice() const;
	Recipe append(const pair<Ingredient *, Amount>& newIngredient)const;
	Recipe operator+(const pair<Ingredient *, Amount> &newIngredient)const;
	bool operator==(const Recipe& recipeData);
	const bool equals(const Recipe& recipeData)const;
	void priceCalculate(const vector<pair<Ingredient *, Amount>>& recipeData);

	
};


#endif //OOP_PROJECT_RECIPE_H

