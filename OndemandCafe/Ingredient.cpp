#include "Ingredient.h"

Ingredient::Ingredient(const string& name, const Price& unitPrice) :m_name(name), m_unitPrice(unitPrice) {
}

Ingredient::~Ingredient(){
}

const Price Ingredient::getUnitPrice() const{
	return m_unitPrice;
}

const string Ingredient::getName()const {
	return m_name;
}

const bool Ingredient::equals(const Ingredient& others)const {
	return m_name == others.m_name;
}

const bool Ingredient::operator==(const Ingredient& others)const {
	return Ingredient::equals(others);
}
