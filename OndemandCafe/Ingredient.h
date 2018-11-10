#pragma once

#include <string>
using namespace std;

class Ingredient
{
private:
	string m_name;
	int m_unitPrice;
public:
	Ingredient(const string& name);
	~Ingredient();
	const int getUnitPrice(void)const;
	const string getName(void)const;
	const bool equals(const Ingredient& others)const;
	const bool operator == (const Ingredient& others)const;
};

