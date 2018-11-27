#pragma once
#include"Product.h"
class OfficeSupplies:public Product
{
	int count;
public:
	OfficeSupplies(int price, string color, string name, int eDay, int eMonth, int eYear, int count);
	void setCount(int count);
	int getCount() const { return count; }

	void info() const override;

};

