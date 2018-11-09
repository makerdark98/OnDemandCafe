#include "Coffee.h"

Coffee::Coffee(const Recipe& recipe) : m_recipe(recipe){

}

Coffee::~Coffee()
{
}

const string Coffee::getName()const
{
	return m_recipe.getCoffeeName();
}

const Recipe Coffee::getRecipe() const
{
	return m_recipe;
}


