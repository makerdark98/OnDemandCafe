#include "CafeFactory.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iterator>
#include <mutex>

using namespace std;

once_flag CafeFactory::m_OnceFlag;
shared_ptr<CafeFactory> CafeFactory::m_instance = nullptr;

vector<string> split(const string& s, char delimiter) {
	std::vector<std::string> tokens;
	std::string token;
	std::istringstream tokenStream(s);
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}


bool CafeFactory::isCoffeeBean(const string & ingredientName)
{
	return m_coffeeBeanString == ingredientName;
}

Menu CafeFactory::createMenu()
{
	ifstream cafeConfig;
	cafeConfig.open(m_cafeConfigFileName);
	getline(cafeConfig, m_coffeeBeanString);
	cafeConfig.close();

	ifstream menuConfig;
	menuConfig.open(m_menuConfigFileName);
	string rawItem;
	vector<Recipe> result;
	while (getline(menuConfig, rawItem)) {
		auto parsedItem = split(rawItem, ',');
		string name = parsedItem[0];
		vector<RecipeData> recipeData;
		shared_ptr<Ingredient> ingredient=nullptr;
		for (unsigned int i = 1; i < parsedItem.size()-1; i+=2) {
			if (isCoffeeBean(parsedItem[i])) {
				ingredient = make_shared<CoffeeBean>();
			}
			else {
				ingredient = make_shared<Ingredient>(parsedItem[i]);
			}
			recipeData.push_back(RecipeData(*ingredient, stoi(parsedItem[i+1])));
		}
	}

	menuConfig.close();

	return Menu(result);
}

CafeFactory::CafeFactory()
{
	setCafeConfig("cafe.config");
	setMenuConfig("menu.config");
}

CafeFactory & CafeFactory::getInstance()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	call_once(CafeFactory::m_OnceFlag, []() {
		m_instance.reset(new CafeFactory);
	});

	return *(m_instance.get());
}

Cafe CafeFactory::createCafe()
{
	return Cafe();
}

void CafeFactory::setCafeConfig(const string & cafeConfig)
{
	m_cafeConfigFileName = cafeConfig;
}

void CafeFactory::setMenuConfig(const string & menuConfig)
{
	m_menuConfigFileName = menuConfig;
}

