#pragma once

#include <string>
using namespace std;
class Ingredient
{
private:
	string name;
	int price;
	int unitPrice;
public:
	Ingredient(const string& name);
	~Ingredient();
	int getPrice(void);
	int getUnitPrice(void);
	const bool equals(const Ingredient& others)const;
	const bool operator == (const Ingredient& others)const;
};

