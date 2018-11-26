#include "Product.h"

Product::Product(int price, string color, int eDay, int eMonth, int eYear)
	:date_(eDay,eMonth,eYear)
{
	date_ d;
	this->price = price;
	this->color = color;
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
void Product::info() const
{
	cout << "Price: " << price << endl;
	cout << "Color: " << color << endl;
	cout << "Expiration date: ";
	date_::print();
	cout << endl;
	cout << "Current date: " << date_::getCurrentDay() << "." << date_::getCurrentMonth() << "." << date_::getCurrentYear() << endl;
}

