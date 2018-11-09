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
public:
	
	Recipe(const vector<pair<Ingredient *, Amount>>& recipeData);
	string getCoffeeName() const;
	void setCoffeeName(const string m_nameOfCoffee);
	Recipe append(const pair<Ingredient *, Amount>& newIngredient)const;
	Recipe operator+(const pair<Ingredient *, Amount> &newIngredient)const;
	bool operator==(const Recipe& recipeData);
	int priceCalculate(const vector<pair<Ingredient *, Amount>>& recipeData);

	
};


#endif //OOP_PROJECT_RECIPE_H

