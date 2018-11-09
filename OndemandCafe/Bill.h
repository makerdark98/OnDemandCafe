#pragma once

#include "stdafx.h"

class Bill {
private:
	vector<Coffee> m_coffees;
public:
	Bill(vector<Coffee> coffees);
	const int getTotalPrice() const;

};
