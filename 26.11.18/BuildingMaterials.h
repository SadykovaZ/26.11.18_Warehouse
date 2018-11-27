#pragma once
#include"Product.h"
class BuildingMaterials :public Product
{
	string type;
public:
	BuildingMaterials(string name, int price, string color, date_ expDate, string type);
	BuildingMaterials() = default;
	void setType(string type);
	string getType() const { return type; }

	void info() const override;
	bool criticalDaysToExpiration()const override;
	string getStringFileInfo()const override;
	void readStringInfo(string &res)override;
};

