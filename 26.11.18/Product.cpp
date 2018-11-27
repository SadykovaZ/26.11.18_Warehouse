#include "Product.h"

Product::Product(int price, string color, string name, int eDay, int eMonth, int eYear)
	:date_(eDay,eMonth,eYear)
{
	date_ d;
	this->price = price;
	this->color = color;
	this->name = name;
	date_::setDay(eDay);
	date_::setMonth(eMonth);
	date_::setYear(eYear);
}
void Product::setPrice(int price)
{
	this->price = price;
}
void Product::setColor(string color)
{
	this->color = color;
}
void Product::setName(string name)
{
	this->name = name;
}
void Product::info() const
{
	cout << "Price: " << price << endl;
	cout << "Color: " << color << endl;
	cout << "Name: " << name<< endl;
	cout << "Expiration date: ";
	date_::print();
	cout << endl;
	cout << "Current date: " << date_::getCurrentDay() << "." << date_::getCurrentMonth() << "." << date_::getCurrentYear() << endl;
}

