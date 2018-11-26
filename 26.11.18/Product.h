#pragma once
#include<iostream>
#include"Date.h"
using namespace std;
class Product abstract :public date_
{
	int price;
	string name;
	//srok godnosti
public:
	Product(int price, string name, int day, int month, int year);
	void setPrice(int price);
	int getPrice() const { return price; }
	void setName(string name);
	string getName() const { return name; }
	void info() const;
	
};

