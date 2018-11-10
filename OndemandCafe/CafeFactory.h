#pragma once
#include "Cafe.h"
class CafeFactory
{
private:
	static once_flag m_OnceFlag;
	static shared_ptr<CafeFactory> m_instance;
	string m_coffeeBeanString;
	string m_cafeConfigFileName;
	string m_menuConfigFileName;

	bool isCoffeeBean(const string& ingredientName);
	Menu createMenu();
	CafeFactory();
	CafeFactory(const CafeFactory &) = delete;
	CafeFactory &operator=(const CafeFactory &) = delete;
public:
	static CafeFactory& getInstance();
	Cafe createCafe();
	void setCafeConfig(const string& cafeConfig);
	void setMenuConfig(const string& menuConfig);
};

