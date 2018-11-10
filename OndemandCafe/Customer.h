#pragma once
#include "Cafe.h"
class Customer
{
protected:
	Cafe& m_cafe;
public:
	Customer(Cafe& cafe) :m_cafe(cafe) {};
	virtual void run() = 0;
	virtual ~Customer() {};
};

