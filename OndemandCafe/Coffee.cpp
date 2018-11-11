#include "Coffee.h"

Coffee::Coffee(const Recipe& recipe) : m_recipe(recipe){
}

Coffee::~Coffee(){
}

void Coffee::setName(const string & newName)
{
	m_recipe.setCoffeeName(newName);
}

const string Coffee::getName()const{
	return m_recipe.getCoffeeName();
}

const int Coffee::getPrice() const{
	return m_recipe.getCoffeePrice();
}

const Recipe Coffee::getRecipe() const{
	return m_recipe;
}

bool Coffee::operator==(const Recipe & recipe) const
{
	return m_recipe == recipe;
}


