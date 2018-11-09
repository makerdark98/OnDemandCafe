#pragma once
#include<string>
#include "Ingredient.h"
using namespace std;

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

