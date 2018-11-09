#include "CoffeeBean.h"


CoffeeBean::CoffeeBean(const string& origin):Ingredient("coffeeBean"),m_origin(origin){
}

CoffeeBean::~CoffeeBean(){
}

bool CoffeeBean::equals(const CoffeeBean& otherCoffeeBean) {
	if (m_origin == otherCoffeeBean.getName()) {
		return true;
	}
	else {
		return false;
	}
}

const string CoffeeBean::getName() const
{
	return m_origin;
}

