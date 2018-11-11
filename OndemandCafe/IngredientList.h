#pragma once
#include "Ingredient.h"
#include <vector>
class IngredientList
{
private:
	vector<Ingredient> m_list;

public:
	IngredientList();
	virtual ~IngredientList();

	IngredientList add(const Ingredient& ingredient) const;
	IngredientList& append(const Ingredient& ingredient);

	IngredientList operator+(const Ingredient& ingredient) const;
	IngredientList& operator+=(const Ingredient& ingredient);

	Ingredient operator[](const unsigned int& idx);
	const Ingredient& operator[](const unsigned int& idx) const;

	size_t size() const;
	
};

