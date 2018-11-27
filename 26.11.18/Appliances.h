#pragma once
#include"Product.h"
class Appliances:public Product
{
	string purpose;
public:
	Appliances(int price, string color, string name, int eDay, int eMonth, int eYear, string purpose);
	void setPurpose(string purpose);
	string getPurpose() const { return purpose; }

	void info() const override;
	
};

