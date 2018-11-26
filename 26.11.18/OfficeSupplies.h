#pragma once
#include"Product.h"
class OfficeSupplies:public Product
{
	string name;
public:
	OfficeSupplies(int price, string color, int eDay, int eMonth, int eYear, string name);
	void setName(string name);
	string getName() const { return name; }

	void info() const override;

};

