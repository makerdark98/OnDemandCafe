#pragma once
#include<string>
using namespace std;
#include "Ingredient.h"
class CoffeeBean:public Ingredient
{
private:
	string m_origin;
public:
	CoffeeBean(const string& origin);
	~CoffeeBean();
	bool equals(const CoffeeBean& otherCoffeeBean);
	const string getName() const;
};

