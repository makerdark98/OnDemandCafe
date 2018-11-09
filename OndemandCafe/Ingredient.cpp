#include "Ingredient.h"

Ingredient::Ingredient(const string& name) :m_name(name) {
}

Ingredient::~Ingredient(){
}

const int Ingredient::getUnitPrice() const{
	return m_unitPrice;
}

const string Ingredient::getName()const {
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
