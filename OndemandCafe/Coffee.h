#pragma once
typedef double Amount;
class Coffee
{
private:
	string nameOfCoffee;
	vector < pair < Ingredient,Amount>> recipeData;
public:
	Coffee(const Recipe& recipe);
	~Coffee();
};

