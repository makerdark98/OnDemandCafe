#include "CliCustomer.h"
#include <iostream>
#include <iomanip>
ostream & operator<<(ostream & os, const Ingredient & ingredient)
{
		os.setf(ios::left);
		os<<setw(30)
		 << ingredient.getName()
		 << setw(3)
		 << "Unit Price : "
		<< ingredient.getUnitPrice();
	return os;
}

ostream & operator<<(ostream & os, const RecipeData & recipeData) 
{
	const Ingredient& ingredient = recipeData.getIngredient();

	os.setf(ios::left);
	os << setw(30)
	 << ingredient.getName()
		<< "Amount : "
		<< setw(3)
		<< recipeData.getAmount();
	return os;
}

ostream & operator<<(ostream & os, const Recipe & recipe)
{
	cout << setw(35);
	os << recipe.getCoffeeName()
		<< "Price :"
		<< recipe.getCoffeePrice();
	return os;
}

ostream & operator<<(ostream & os, const Menu & menu)
{
	for (unsigned int i = 0; i < menu.size(); i++) {
		os << i << ". "
			<< menu[i]
			<< endl;
	}
	return os;
}

ostream & operator<<(ostream & os, const Coffee & coffee)
{
	os << "Coffee Name :";
	os << left;
	os.width(20);
	os << coffee.getName();
	os << right;
	os << "Price :"
		<< coffee.getPrice();

	return os;
}

ostream & operator<<(ostream & os, const IngredientList& ingredients)
{
	os << "< Ingredient List >"
		<< endl
		<< endl;
	for (unsigned int i = 0; i < ingredients.size(); i++) {
		os << i << ". "
			<< ingredients[i]
			<< endl;
	}

	return os;
}

OrderType::OrderType(const string & name, function<void(void)> func)
{
	m_name = name;
	m_func = func;
}

ostream & operator<<(ostream & os, OrderType & ot)
{
	os << ot.m_name;
	return os;
}

void CliCustomer::orderCommon() const
{
	cout << "아래 메뉴 중 원하시는 걸 선택해주세요" << endl;
	cout << "=================================================="<<endl;
	cout << " <  Menu  >" << endl<<endl;
	cout.setf(ios::left);
	cout <<m_cafe.getMenu()<< endl;
	int order;
	cin >> order;

	Coffee& coffee = m_cafe.orderMenu(order);

	cout << "\n\n 커피에 토핑을 추가 하시겠습니까? (Y/n)" << endl;
	char c;
	cin >> c;
	if (tolower(c) == 'y') {
		vector<RecipeData> topping_data;
		Recipe recipe = coffee.getRecipe();
		int topping_order;
		Amount amount;
		const IngredientList& topping = m_cafe.getIngredientList();
		while (true) {
			cout << " 추가할 재료를 고르세요"
				<< endl
				<< "==========================================================="
				<< endl
				<< topping
				<< endl
				<< topping.size()
				<< ". 토핑 추가 끝내기"
				<< endl;
			cin >> topping_order;
			if (topping_order == topping.size()) {
				break;
			}
			cout << "추가 할 양을 넣으세요" << endl;
			cin >> amount;
			cout << "===========================================================" << endl;
			topping_data.push_back(RecipeData(topping[order], amount));
			cout << "추가된 토핑 리스트" << endl;
			for (unsigned int i = 0; i < topping_data.size(); i++) {
				cout << topping_data[i] << endl;
			}
		}
		recipe=recipe.append(topping_data);
		//TODO 원래 커피 가격에 추가한 재료의 가격을 더하는 것만 하면 됨.
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

		cout<< ". 조합 끝내기"<< endl;
		cin >> order;
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
