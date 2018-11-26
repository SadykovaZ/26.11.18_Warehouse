#include "BuildingMaterials.h"


BuildingMaterials::BuildingMaterials(int price, string color, int eDay, int eMonth, int eYear, string name)
	:Product(price, color, eDay, eMonth, eYear)
{
	this->name = name;
}

void BuildingMaterials::setName(string name)
{
	this->name = name;
}

void BuildingMaterials::info() const
{
	Product::info();
	cout << "Name of office supply: " << name << endl;
}
