#pragma once
#include<iostream>
#include"Date.h"
#include<string>
using namespace std;
class Product abstract :public date_
{
	int price;
	string color;
	string name;
	int leftDay;
	
public:
	Product(int price, string color, string name,int eDay, int eMonth, int eYear);
	void setPrice(int price);
	int getPrice() const { return price; }
	void setColor(string color);
	string getColor() const { return color; }
	void setName(string name);
	string getName() const { return name; }
	virtual void info() const;
	
};

