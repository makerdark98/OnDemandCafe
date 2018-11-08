#include<iostream>
#include<string>
#include "Ingredient.h"
using namespace std;

Ingredient::Ingredient(const string& name) :name(name) {
}

Ingredient::~Ingredient(){
}

int Ingredient::getPrice() {
	return price;
}

int Ingredient::getUnitPrice() {
	return unitPrice;
}

const bool Ingredient::equals(const Ingredient& others)const {
	if (name == others.name){
		return true;
	}
	else {
		return false;
	}
}

const bool Ingredient::operator==(const Ingredient& others)const {
	Ingredient::equals(others);
}
