#pragma once
#include"Product.h"
#include<vector>
using namespace std;
class Warehouse
{
	string wName;
	vector<unique_ptr<Product>> products;
public:
	void setWName(string wName);
	string getWName() const { return wName; }
	Warehouse(string wName);
	void addProduct(Product* product);
	void delProduct(Product* product);
	void getInfo() const;
	void productCriticExpDate();
	void overdueProduct();

	int getCountOfProduct() const { return products.size(); }
	
	
};

