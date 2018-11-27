#pragma once
#include"Product.h"
class Appliances:public Product
{
	string purpose;
public:
	Appliances(string name, int price, string color, date_ expDate, string purpose);
	Appliances() = default;
	void setPurpose(string purpose);
	string getPurpose() const { return purpose; }

	void info() const override;
	bool criticalDaysToExpiration()const override;
	
	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

