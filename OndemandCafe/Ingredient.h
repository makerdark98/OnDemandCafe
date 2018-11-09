#pragma once

#include <string>
using namespace std;
class Ingredient
{
private:
	string m_name;
	int m_price;
	int m_unitPrice;
public:
	Ingredient(const string& name);
	~Ingredient();
	int getPrice(void);
	int getUnitPrice(void);
	string getName(void);
	const bool equals(const Ingredient& others)const;
	const bool operator == (const Ingredient& others)const;
};

