#include "Warehouse.h"
void Warehouse::setWName(string wName)
{
	this->wName = wName;
}

Warehouse::Warehouse(string wName)
{
	this->wName = wName;
}

void Warehouse::addProduct(Product * product)
{
	products.push_back(unique_ptr<Product>(product));
}
void Warehouse::delProduct(Product * product)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].get() == product) {
			products.erase(begin(products) + i);
			return;
		}
	}
}
void Warehouse::getInfo() const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		products[i]->info();
	}
}

void Warehouse::productCriticExpDate()
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if ((products[i]->getCurrentDay()- (products[i]->getDay())) < 7)
		{
			products[i]->info();
		}
	}
}
void Warehouse::overdueProduct() 
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if ((products[i]->getDay() < products[i]->getCurrentDay()) || (products[i]->getMonth() < products[i]->getCurrentMonth()) || (products[i]->getYear() < products[i]->getCurrentYear()))
		{
			products[i]->info();
		}
	}
}
