#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include "Barista.h"
#include"Coffee.h"
#include"Ingredient.h"
using namespace std;

Barista::Barista()
{
}

Barista::~Barista()
{
}

Coffee Barista::makeCoffee(const Recipe& recipe) {
	Coffee coffee = Coffee(recipe);
	return coffee;
}