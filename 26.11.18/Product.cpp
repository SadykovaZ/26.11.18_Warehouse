#include "Product.h"

int Product::prodCode = 0;
Product::Product(string name, int price, string color, date_ expDate)
	
{	
	this->id = ++prodCode;	
	this->name = name;
	this->price = price;
	this->color = color;
	this->expDate = expDate;
}
Product::Product(){ this->id = ++prodCode; }
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

void Product::setExpDate(date_ expDate)
{
	this->expDate = expDate;
}
void Product::setExpDate2(int day, int month, int year)
{
	this->expDate.setDay(day);
	this->expDate.setMonth(month);
	this->expDate.setYear(year);

}
int Product::leftDays() const
{
	int lDays;
	lDays = this->expDate.getDay() - this->expDate.getCurrentDay() + (this->expDate.getMonth() - this->expDate.getCurrentMonth()) * 30 + (this->expDate.getYear() - this->expDate.getCurrentYear()) * 12 * 30;
	return lDays;
}
void Product::info() const
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name<< endl;
	cout << "Price: " << price << endl;
	cout << "Color: " << color << endl;
	cout << "Expiration date: " << expDate;	
}


string Product::getStringFileInfo() const
{
	char d = ';';
	string res = typeid(*this).name();
	res = res.substr(6) + d;
	res += getName() += d;
	res += to_string(getPrice()) += d;
	res += getColor() += d;
	res += getStrExpDate() += d;

	return res;
}

void Product::readStringInfo(string & str)
{
	string info[6];
	for (size_t i = 0; i < 6; i++)
	{
		info[i] = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->setName(info[0]);
	this->setPrice(stoi(info[1]));
	this->setColor(info[2]);
	this->setExpDate2(stoi(info[3]),stoi(info[4]),stoi(info[5]));
}

