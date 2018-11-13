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


//bool CafeFactory::isCoffeeBean(const string & ingredientName)
//{
//	for (const string& item : m_coffeeBeans) {
//		if (item == ingredientName) {
//			return true;
//		}
//	}
//	return false;
//}

Menu CafeFactory::createMenu()
{
	Menu& result = readMenuConfig();

	return result;
}

IngredientList CafeFactory::createIngredientLists()
{
	IngredientList ingredients;
	for (auto item : ingredientUnitPrice) {
		ingredients.append(Ingredient(item.first, item.second));
	}
	return ingredients;
}

CafeFactory::CafeFactory()
{
	//setCoffeeBeanConfig("coffeebean.config");
	setIngredientConfig("ingredient.config");
	setMenuConfig("menu.config");
}

//void CafeFactory::readCafeConfig()
//{
//	ifstream cafeConfig;
//	cafeConfig.open(m_cafeConfigFileName);
//	string rawData;
//	while (getline(cafeConfig, rawData)) {
//		m_coffeeBeans.push_back(rawData);
//	}
//	cafeConfig.close();
//}

void CafeFactory::readIngredientConfig()
{
	ifstream ingredientConfig;
	ingredientConfig.open(m_ingredientConfigFileName);
	string rawData;
	while (getline(ingredientConfig, rawData)) {
		vector<string> parsedData = split(rawData, ',');
		for (unsigned int i = 0; i < parsedData.size() - 1; i += 2) {
			ingredientUnitPrice[parsedData[i]] = stoi(parsedData[i + 1]);
		}
	}
}

Menu CafeFactory::readMenuConfig()
{
	ifstream menuConfig;
	menuConfig.open(m_menuConfigFileName);
	string rawItem;
	vector<Recipe> result;
	while (getline(menuConfig, rawItem)) {
		vector<RecipeData> recipeData;
		vector<string> parsedItem = split(rawItem, ',');
		string name = parsedItem[0];
		shared_ptr<Ingredient> ingredient = nullptr;
		for (unsigned int i = 1; i < parsedItem.size() - 1; i += 2) {
			ingredient = make_shared<Ingredient>(parsedItem[i], ingredientUnitPrice[parsedItem[i]]);
			recipeData.push_back(RecipeData(*ingredient, stoi(parsedItem[i + 1])));
		}
		result.push_back(Recipe(name, recipeData));
	}

	menuConfig.close();
	return Menu(result);

}

CafeFactory & CafeFactory::getInstance()
{
	call_once(CafeFactory::m_OnceFlag, []() {
		m_instance.reset(new CafeFactory);
	});

	return *(m_instance.get());
}

Cafe CafeFactory::createCafe()
{
	//readCafeConfig();
	readIngredientConfig();
	return Cafe(createMenu(), createIngredientLists());
}

//void CafeFactory::setCoffeeBeanConfig(const string & cafeConfig)
//{
//	m_cafeConfigFileName = cafeConfig;
//}

void CafeFactory::setIngredientConfig(const string & ingredientConfig)
{
	m_ingredientConfigFileName = ingredientConfig;
}

void CafeFactory::setMenuConfig(const string & menuConfig)
{
	m_menuConfigFileName = menuConfig;
}

