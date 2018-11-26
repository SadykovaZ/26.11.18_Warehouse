#pragma once
#include<iostream>
#include"Date.h"
#include<string>
using namespace std;
class Product abstract :public date_
{
	int price;
	string color;
	
	int leftDay;
	
public:
	Product(int price, string color, int eDay, int eMonth, int eYear);
	void setPrice(int price);
	int getPrice() const { return price; }
	void setColor(string color);
	string getColor() const { return color; }

	virtual void info() const;
	
};

