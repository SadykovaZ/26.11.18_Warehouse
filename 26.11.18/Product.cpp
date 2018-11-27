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
void Product::info() const
{
	cout << "ID: " << id << endl;
	cout << "Name: " << name<< endl;
	cout << "Price: " << price << endl;
	cout << "Color: " << color << endl;
	cout << "Expiration date: " << expDate << endl;	
}
bool Product::expiredDate() const
{
	
	if (daysToDateFromCurrDate(this->expDate) < 0) 
	{		
		return true;
	}
	return false;
}

string Product::getStringFileInfo() const
{
	char d = ';';
	string res = typeid(*this).name();
	res = res.substr(6) + d;
	res += getName() += d;
	res += to_string(getPrice()) += d;
	res += getColor() += d;
	res += to_string(getExpDate()) += d;

	return res;
}

void Product::readStringInfo(string & str)
{
	string info[4];
	for (size_t i = 0; i < 4; i++)
	{
		info[i] = str.substr(0, str.find(';'));
		str = str.substr(str.find(';') + 1);
	}
	this->setName(info[0]);
	this->setPrice(stoi(info[1]));
	this->setColor(info[2]);
	this->setExpDate(stoi(info[3]));
}

