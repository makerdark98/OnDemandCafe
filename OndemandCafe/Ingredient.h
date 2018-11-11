#pragma once

#include <string>
using Price = int;
using namespace std;

class Ingredient
{
private:
	string m_name;
	Price m_unitPrice;
public:
	Ingredient(const string& name, const Price& price);
	~Ingredient();
	const Price getUnitPrice(void)const;
	const string getName(void)const;
	const bool equals(const Ingredient& others)const;
	const bool operator == (const Ingredient& others)const;
};

