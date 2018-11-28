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
	bool flag = false;
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i].get() == product) {
			flag = true;
			products.erase(begin(products) + i);
		}
	}
	if (flag == false)
		cout << "not avaliable\n";
}
void Warehouse::getInfo() const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		products[i]->info();

	}
}

void Warehouse::productCriticExpDate() const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i]->leftDays() <= 7 && products[i]->leftDays() > 0)
		{

			products[i]->info();

		}
	}
}
void Warehouse::overdueProduct() const
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i]->leftDays() < 0)
		{
			products[i]->info();
		}
	}
}

bool Warehouse::removeProductById(int id)
{
	for (size_t i = 0; i < products.size(); i++)
	{
		if (products[i]->getId() == id) {
			products.erase(begin(products) + i);
			return true;
		}
	}
	return false;
}
