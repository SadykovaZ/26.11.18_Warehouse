#include "BuildingMaterials.h"


BuildingMaterials::BuildingMaterials(int price, string color, string name, int eDay, int eMonth, int eYear, string type)
	:Product(price, color, name, eDay, eMonth, eYear)
{
	this->type = type;
}

void BuildingMaterials::setType(string type)
{
	this->type = type;
}

void BuildingMaterials::info() const
{
	Product::info();
	cout << "Type of office supply: " << type << endl;
}
