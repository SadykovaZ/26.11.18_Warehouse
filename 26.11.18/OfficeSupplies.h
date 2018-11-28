#pragma once
#include"Product.h"
#include <string>
class OfficeSupplies:public Product
{
	int count;
public:
	OfficeSupplies(string name, int price, string color, date_ expDate, int count);
	OfficeSupplies() = default;
	void setCount(int count);
	int getCount() const { return count; }

	void info() const override;
	
	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

