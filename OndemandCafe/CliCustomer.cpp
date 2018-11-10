#include "CliCustomer.h"
#include <iostream>

const map<int, string> CliCustomer::orderMap = {
	{0, "COMMON"},
	{1, "CUSTOM"}
};

void CliCustomer::printMenuItem(const MenuItem& item) const
{
	const Recipe& recipe = item.getRecipe();
	cout << "Coffee Name : "
		<< recipe.getCoffeeName()
		<< " Cost :"
		<< recipe.getCoffeePrice();

}

void CliCustomer::printMenu() const
{
	const Menu& menu = m_cafe.getMenu();
	for (auto item : menu) {
		printMenuItem(item);
	}
}

void CliCustomer::askOrder() const
{
	cout << "원하시는 주문방식를 입력해주세요("
		<< 0 << "~" << orderMap.size() - 1 << ")" << endl;
	for (auto orderOption : orderMap) {
		cout << orderOption.first << "." << orderOption.second << endl;
	}
}

CliCustomer::CliCustomer(Cafe & cafe)
	:Customer(cafe)
{
}


CliCustomer::~CliCustomer()
{
}

void CliCustomer::run() {
	const Menu& menu = m_cafe.getMenu();
	askOrder();
	printMenu();
}
