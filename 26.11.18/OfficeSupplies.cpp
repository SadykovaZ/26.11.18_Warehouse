#include "OfficeSupplies.h"

OfficeSupplies::OfficeSupplies(int price, string color, int eDay, int eMonth, int eYear, string name)
	:Product(price, color, eDay, eMonth, eYear)
{
	this->name = name;
}
void OfficeSupplies::setName(string name)
{
	this->name = name;
}
void OfficeSupplies::info() const
{
	Product::info();
	cout << "Name of office supply: " << name << endl;
}
