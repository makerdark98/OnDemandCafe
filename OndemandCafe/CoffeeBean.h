#pragma once
#include<string>
#include "Ingredient.h"
using namespace std;

class CoffeeBean:public Ingredient
{
private:
	string m_origin;
public:
	CoffeeBean();
	CoffeeBean(const string& origin);
	~CoffeeBean();
	const bool equals(const CoffeeBean& otherCoffeeBean)const;
	const bool operator==(const CoffeeBean& otherCoffeeBean)const;
	const string getName() const;
};

