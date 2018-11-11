#pragma once
#include "Cafe.h"
#include <map>
class CafeFactory
{
private:
	static once_flag m_OnceFlag;
	static shared_ptr<CafeFactory> m_instance;
	string m_coffeeBeanString;
	string m_cafeConfigFileName;
	string m_ingredientConfigFileName;
	string m_menuConfigFileName;
	map<string, Price> ingredientUnitPrice;

	bool isCoffeeBean(const string& ingredientName);
	Menu createMenu();
	CafeFactory();
	CafeFactory(const CafeFactory &) = delete;
	CafeFactory &operator=(const CafeFactory &) = delete;

	void readCafeConfig();
	void readIngredientConfig();
	Menu readMenuConfig();


public:
	static CafeFactory& getInstance();
	Cafe createCafe();
	void setCafeConfig(const string& cafeConfig);
	void setIngredientConfig(const string& ingredientConfig);
	void setMenuConfig(const string& menuConfig);
};

