#include "CafeFactory.h"
#include "CliCustomer.h"

int main() {
	Cafe cafe = CafeFactory::getInstance().createCafe("ingredient.config", "menu.config");
	CliCustomer customer(cafe);
	customer.run();
	return 0;
}