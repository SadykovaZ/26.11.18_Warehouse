#include "OfficeSupplies.h"

OfficeSupplies::OfficeSupplies(int price, string color, string name, int eDay, int eMonth, int eYear, int count)
	:Product(price, color, name, eDay, eMonth, eYear)
{
	this->count = count;
}
void OfficeSupplies::setCount(int count)
{
	this->count = count;
}
void OfficeSupplies::info() const
{
	Product::info();
	cout << "Count of office supply: " << count << endl;
}
