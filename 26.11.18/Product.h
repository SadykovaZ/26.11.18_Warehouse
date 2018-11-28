#pragma once
#include<iostream>
#include"Date.h"
#include<string>
using namespace std;
class Product abstract 
{
	int price;
	string color;
	string name;
	date_ expDate;
	
	int id;
	static int prodCode;
	
public:
	Product(string name, int price, string color, date_ expDate);
	Product();
	void setPrice(int price);
	int getPrice() const { return price; }
	void setColor(string color);
	string getColor() const { return color; }
	void setName(string name);
	string getName() const { return name; }

	void setExpDate(date_ expDate);
	void setExpDate2(int day, int month, int year);
	int leftDays() const;

	string getStrExpDate()const { return expDate.getStrInfo(); }
	date_ getExpDate()const { return expDate; }


	int getId()const { return id; }
	string getProductType()const { return string(typeid(*this).name()).substr(6); }


	virtual void info() const;
	
	

	virtual string getStringFileInfo()const;
	virtual void readStringInfo(string &str);
	
};

