#include "CliCustomer.h"
#include <iostream>
#include <iomanip>

bool isValid(int i, pair<int, int> range) {
	return range.first <= i && i < range.second;
}

ostream & operator<<(ostream & os, const Ingredient & ingredient)
{
	os << left << setw(30) << ingredient.getName();
	os << setw(3) << "Unit Price : " << ingredient.getUnitPrice();
	return os;
}

ostream & operator<<(ostream & os, const RecipeData & recipeData)
{
	const Ingredient& ingredient = recipeData.getIngredient();
	os << setw(30) << ingredient.getName();
	os << "Amount : " << setw(3) << recipeData.getAmount();
	return os;
}

ostream & operator<<(ostream & os, const Recipe & recipe)
{
	os << setw(35) << recipe.getCoffeeName();
	os << "Price : " << recipe.getCoffeePrice();
	return os;
}

ostream & operator<<(ostream & os, const Menu & menu)
{
	for (unsigned int i = 0; i < menu.size(); i++) {
		os << right << setw(2) << i << left << ". " << menu[i] << endl;
	}
	return os;
}

ostream & operator<<(ostream & os, const Coffee & coffee)
{
	os << "Coffee Name :";
	os.width(20);
	os << coffee.getName();
	os << right << "Price :" << coffee.getPrice();
	os << left;
	return os;
}

ostream & operator<<(ostream & os, const IngredientList& ingredients)
{
	os << "< Ingredient List >\n" << endl;
	for (unsigned int i = 0; i < ingredients.size(); i++) {
		os << i << ". " << ingredients[i] << endl;
	}

	return os;
}

OrderType::OrderType(const string & name, function<void(void)> func)
{
	m_name = name;
	m_func = func;
}

ostream & operator<<(ostream & os, const OrderType & ot)
{
	os << ot.m_name;
	return os;
}

void CliCustomer::orderCommon() const
{
	const Menu& menu = m_cafe.getMenu();

	cout << "아래 메뉴 중 원하시는 걸 선택해주세요" << endl;
	cout << "==================================================" << endl;
	cout << " <  Menu  >\n" << endl;
	cout << menu << endl;
	int order;
	cin >> order;
	while (!isValid(order, { 0, menu.size() })) {
		cout << "다시 입력해주세요 " << endl;
		cin >> order;
	}

	Coffee& coffee = m_cafe.orderMenu(order);

	cout << "\n\n 커피에 토핑을 추가 하시겠습니까? (Y/n)" << endl;
	char c;
	cin >> c;
	if (tolower(c) == 'y') {
		vector<RecipeData> topping_data;
		int topping_order;
		Amount amount;
		const IngredientList& topping = m_cafe.getIngredientList();
		while (true) {
			cout << " 추가할 재료를 고르세요\n";
			cout << "===========================================================" << endl;
			cout << topping << endl;
			cout << topping.size() << ". 토핑 추가 끝내기" << endl;
			cin >> topping_order;
			while (!isValid(topping_order, { 0, topping.size()+1 })) {
				cout << "다시 입력해주세요 " << endl;
				cin >> topping_order;
			}
			if (topping_order == topping.size()) {
				break;
			}
			cout << "추가 할 양을 넣으세요" << endl;
			cin >> amount;
			cout << "===========================================================" << endl;
			topping_data.push_back(RecipeData(topping[topping_order], amount));
			cout << "추가된 토핑 리스트" << endl;
			for (unsigned int i = 0; i < topping_data.size(); i++) {
				cout << topping_data[i] << endl;
			}
		}
		coffee.append(topping_data);

		char check;
		cout << "\n 새로운 이름을 지정하시겠습니까? (Y/n)" << endl;
		cin >> check;
		if (tolower(check) == 'y') {
			cout << "새로운 메뉴의 이름을 입력해주세요 :";
			cin.ignore();
			string name;
			getline(cin, name);
			Recipe recipe = coffee.getRecipe();;
			recipe.setCoffeeName(name);
			coffee.setName(name);
			m_cafe.getMenu().addMenuItem(recipe);
		}
	}
	cout << coffee << endl;
}

void CliCustomer::orderCustom() const
{
	vector<RecipeData> data;
	const IngredientList& ingredients = m_cafe.getIngredientList();
	int order;
	Amount amount;
	while (true) {
		cout << "조합할 재료를 고르세요" << endl;
		cout << "============================================================" << endl;
		cout << ingredients << endl;
		cout << ingredients.size();

		cout << ". 조합 끝내기" << endl;
		cin >> order;
		while (!isValid(order, { 0, ingredients.size()+1 })) {
			cout << "다시 입력해주세요 " << endl;
			cin >> order;
		}
		if (order == ingredients.size()) break;
		cout << "조합할 양을 넣으세요" << endl;
		cin >> amount;
		cout << "===========================================================" << endl;
		data.push_back(RecipeData(ingredients[order], amount));
		cout << "지금까지 조합된 리스트" << endl;
		for (unsigned int i = 0; i < data.size(); i++) {
			cout << data[i] << endl;
		}
	}

	if (data.size() == 0) return;
	Coffee& coffee = m_cafe.orderCustom(data);
	if (coffee.getName() == "") {
		cout << "이름을 지으시겠습니까?(Y/n) : ";
		char c;
		cin >> c;
		if (tolower(c) == 'y') {
			cout << "새로운 메뉴의 이름을 입력해주세요 : ";
			cin.ignore();
			string name;
			getline(cin, name);
			Recipe recipe(name, data);
			m_cafe.getMenu().addMenuItem(recipe);
			coffee.setName(name);

		}
	}
	cout << coffee << endl;
}

void CliCustomer::exit()
{
	cout << "Good Bye" << endl;
	bAgain = false;
}

OrderType CliCustomer::askOrder() const
{
	cout << "원하시는 주문방식를 입력해주세요" << endl;
	for (const auto& orderOption : orderMap) {
		cout << orderOption.first << "." << orderOption.second << endl;
	}

	int inputOrder;
	try {
		cin >> inputOrder;
		return orderMap.at(inputOrder);
	}
	catch (...) {
		return OrderType("Retry", []()->void {
			cout << "입력 방식이 잘못되었습니다." << endl;
			cout << "다시 입력해주세요" << endl;
		});
	}
}

CliCustomer::CliCustomer(Cafe & cafe)
	:Customer(cafe),
	orderMap({
		{0, OrderType("Common", bind(&CliCustomer::orderCommon, this))},
		{1, OrderType("Custom", bind(&CliCustomer::orderCustom, this))},
		{2, OrderType("Exit", bind(&CliCustomer::exit, this))}
		}),
	bAgain(true)
{
}
CliCustomer::~CliCustomer()
{

}

void CliCustomer::run() {
	while (bAgain) {
		OrderType& orderType = askOrder();
		orderType.m_func();
	}
}
