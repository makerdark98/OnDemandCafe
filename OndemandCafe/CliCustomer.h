#pragma once
#include "Customer.h"
#include <map>
#include <functional>
class CliCustomer;
class OrderType;

class OrderType {
private:
	string m_name;
public:
	function<void(void)> m_func;

	OrderType(const string& name, function<void(void)> func);
	friend ostream& operator<<(ostream& os, const OrderType& ot);
};

class CliCustomer :
	public Customer
{
private:
	const map<int, OrderType> orderMap;
	bool bAgain;

	void orderCommon() const;
	void orderCustom() const;
	void exit();
	OrderType askOrder() const;

public:
	CliCustomer(Cafe& cafe);;
	~CliCustomer();

	void run();
};

