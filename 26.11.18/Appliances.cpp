#include "Appliances.h"
Appliances::Appliances(int price, string color, int eDay, int eMonth, int eYear, string name)
	:Product(price, color, eDay, eMonth, eYear)
{
	this->name = name;
}
void Appliances::setName(string name)
{
	this->name = name;
}
void Appliances::info() const
{
	Product::info();
	cout << "Name of appliance: " << name << endl;
}
