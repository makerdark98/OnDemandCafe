#include "Ingredient.h"

Ingredient::Ingredient(const string& name) :m_name(name) {
}

Ingredient::~Ingredient(){
}

int Ingredient::getPrice() {
	return m_price;
}

int Ingredient::getUnitPrice() {
	return m_unitPrice;
}

string Ingredient::getName() {
	return m_name;
}

const bool Ingredient::equals(const Ingredient& others)const {
	if (m_name == others.m_name){
		return true;
	}
	else {
		return false;
	}
}

const bool Ingredient::operator==(const Ingredient& others)const {
	return Ingredient::equals(others);
}
