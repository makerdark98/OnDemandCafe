#include "CoffeeBean.h"

CoffeeBean::CoffeeBean()
	:Ingredient("coffeeBean", 100),m_origin("Ethiopia")
{
}

CoffeeBean::CoffeeBean(const string& origin, const Price& unitPrice)
	:Ingredient("coffeeBean", unitPrice),m_origin(origin){
}

CoffeeBean::~CoffeeBean(){
}

const bool CoffeeBean::equals(const CoffeeBean& otherCoffeeBean)const{
	if (m_origin == otherCoffeeBean.getName()) {
		return true;
	}
	else {
		return false;
	}
}

const bool CoffeeBean::operator==(const CoffeeBean & otherCoffeeBean) const{
	return CoffeeBean::equals(otherCoffeeBean);
}

const string CoffeeBean::getName() const{
	return m_origin;
}

