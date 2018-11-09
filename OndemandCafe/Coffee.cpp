#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include "Coffee.h"
#include "Recipe.h"
#include"Ingredient.h"
using namespace std;

Coffee::Coffee(const Recipe& recipe) : m_recipe(recipe){

}

Coffee::~Coffee()
{
}

string Coffee::getName()
{
	return m_recipe.getCoffeeName();
}

const Recipe Coffee::getRecipe() const
{
	return m_recipe;
}


