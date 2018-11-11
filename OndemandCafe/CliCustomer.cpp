#include "CliCustomer.h"
#include <iostream>

void CliCustomer::orderCommon() const
{
	cout << "아래 메뉴중 원하시는 걸 선택해주세요" << endl;
	printMenu();
}

void CliCustomer::orderCustom() const
{
}

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

OrderType CliCustomer::askOrder() const
{
	cout << "원하시는 주문방식를 입력해주세요("
		<< 0 << "~" << orderMap.size() - 1 << ")" << endl;
	for (auto orderOption : orderMap) {
		cout << orderOption.first << "." << orderOption.second << endl;
	}
	int inputOrder;
	cin >> inputOrder;
	return orderMap.at(inputOrder);
}

CliCustomer::CliCustomer(Cafe & cafe)
	:Customer(cafe),
	orderMap({ 
		{0, OrderType("COMMON", bind(&CliCustomer::orderCommon, this))},
		{1, OrderType("CUSTOM", bind(&CliCustomer::orderCustom, this))}
	})
{
}


CliCustomer::~CliCustomer()
{
}

void CliCustomer::run() {
	const Menu& menu = m_cafe.getMenu();
	OrderType& orderType = askOrder();
	orderType.m_func();
}

ostream & operator<<(ostream & os, OrderType & ot)
{
	os << ot.m_name;
	return os;
}

OrderType::OrderType(const string & name, function<void(void)> func)
{
	m_name = name;
	m_func = func;
}

