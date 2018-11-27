#include "Appliances.h"
Appliances::Appliances(int price, string color, string name, int eDay, int eMonth, int eYear, string purpose)
	:Product(price, color, name, eDay, eMonth, eYear)
{
	this->purpose = purpose;
}
void Appliances::setPurpose(string purpose)
{
	this->purpose = purpose;
}
void Appliances::info() const
{
	Product::info();
	cout << "Purpose of appliance: " << purpose << endl;
}
