#pragma once
#include "Cafe.h"
#include <map>
class CafeFactory
{
private:
	static once_flag m_OnceFlag;
	static shared_ptr<CafeFactory> m_instance;
	vector<string> m_coffeeBeans;
	map<string, Price> ingredientUnitPrice;

	Menu createMenu(const string& menuConfigFileName);
	IngredientList createIngredientLists();
	CafeFactory();
	CafeFactory(const CafeFactory &) = delete;
	CafeFactory &operator=(const CafeFactory &) = delete;

	void readIngredientConfig(const string& ingredientConfigFileName);
	Menu readMenuConfig(const string& menuConfigFileName);

public:
	static CafeFactory& getInstance();
	Cafe createCafe(const string& ingredientConfigFileName, const string& menuConfigFileName);
};

