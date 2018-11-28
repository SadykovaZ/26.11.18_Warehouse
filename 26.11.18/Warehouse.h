#pragma once
#include"Product.h"
#include<vector>
#include<fstream>
using namespace std;
class Warehouse
{
	string wName;
	vector<unique_ptr<Product>> products;
public:
	Warehouse(string wName);
	void setWName(string wName);
	string getWName() const { return wName; }
	
	void addProduct(Product* product);
	void delProduct(Product* product);
	void getInfo() const;
	void productCriticExpDate() const;
	void overdueProduct() const;

	bool removeProductById(int id);
	Product& operator [](int index) {
		return *products[index];
	}
	const Product& operator [](int index) const {
		return *products[index];
	}

	int getCountOfProduct() const { return products.size(); }	


};

