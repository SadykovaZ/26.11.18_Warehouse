#include "Product.h"

Product::Product(int price, string name, int day, int month, int year)
	:date_(day,month, year)
{
	this->price = price;
	this->name = name;	
	date_::setDay(day);
	date_::setMonth(month);
	date_::setYear(year);
}
void Product::setPrice(int price)
{
	this->price = price;
}
void Product::setName(string name)
{
	this->name = name;
}

void Product::info() const
{	
	cout << price << " " << name<<endl;	
	date_::print();
}

