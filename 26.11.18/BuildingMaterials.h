#pragma once
#include"Product.h"
class BuildingMaterials :public Product
{
	string type;
public:
	BuildingMaterials(int price, string color, string name, int eDay, int eMonth, int eYear, string type);
	void setType(string type);
	string getType() const { return type; }

	void info() const override;
};

