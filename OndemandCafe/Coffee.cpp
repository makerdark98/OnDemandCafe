#include<iostream>
#include<string>
#include<utility>
#include<vector>
#include "Coffee.h"
#include "Recipe.h"
#include"Ingredient.h"
using namespace std;

Coffee::Coffee(const Recipe& recipe){
	nameOfCoffee = recipe.nameOfCoffee;
	recipeData = recipe.recipeData;

}

Coffee::~Coffee()
{
}
