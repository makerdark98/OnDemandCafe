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
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, delimiter))
	{
		tokens.push_back(token);
	}
	return tokens;
}

Menu CafeFactory::createMenu(const string& menuConfigFileName)
{
	Menu& result = readMenuConfig(menuConfigFileName);
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
}

void CafeFactory::readIngredientConfig(const string& ingredientConfigFileName)
{
	ifstream ingredientConfig;
	ingredientConfig.open(ingredientConfigFileName);
	string rawData;
	while (getline(ingredientConfig, rawData)) {
		vector<string> parsedData = split(rawData, ',');
		for (unsigned int i = 0; i < parsedData.size() - 1; i += 2) {
			ingredientUnitPrice[parsedData[i]] = stoi(parsedData[i + 1]);
		}
	}
}

Menu CafeFactory::readMenuConfig(const string& menuConfigFileName)
{
	ifstream menuConfig;
	menuConfig.open(menuConfigFileName);
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

Cafe CafeFactory::createCafe(const string & ingredientConfigFileName, const string & menuConfigFileName)
{
	readIngredientConfig(ingredientConfigFileName);
	return Cafe(createMenu(menuConfigFileName), createIngredientLists());
}
