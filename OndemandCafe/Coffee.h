#pragma once

#include "Recipe.h"
using namespace std;

class Coffee
{
private:
	Recipe m_recipe;
public:
	Coffee(const Recipe& recipe);
	~Coffee();

	void setName(const string& newName);
	Coffee& append(const vector<RecipeData>& moreIngredient);
	const string getName()const;
	const int getPrice() const;
	const Recipe getRecipe() const;

	bool operator==(const Recipe& recipe) const;
};

