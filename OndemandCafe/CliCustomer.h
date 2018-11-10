#pragma once
#include "Customer.h"
#include <map>
class CliCustomer :
	public Customer
{
private:

	static const map<int, string> orderMap;

	void printMenuItem(const MenuItem& item) const;
	void printMenu() const;
	void askOrder() const;
public:
	CliCustomer(Cafe& cafe);;
	~CliCustomer();
	void run();
};

