#include "IngredientList.h"



IngredientList::IngredientList()
{
}


IngredientList::~IngredientList()
{
}

IngredientList IngredientList::add(const Ingredient & ingredient) const
{
	IngredientList result = *this;
	result.m_list.push_back(ingredient);
	return result;
}

IngredientList & IngredientList::append(const Ingredient & ingredient)
{
	m_list.push_back(ingredient);
	return *this;
}

IngredientList IngredientList::operator+(const Ingredient & ingredient) const
{
	return add(ingredient);
}

IngredientList & IngredientList::operator+=(const Ingredient & ingredient)
{
	return append(ingredient);
}

Ingredient IngredientList::operator[](const unsigned int & idx)
{
	return m_list[idx];
}

const Ingredient & IngredientList::operator[](const unsigned int & idx) const
{
	return m_list[idx];
}

size_t IngredientList::size() const
{
	return m_list.size();
}
