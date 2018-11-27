#include "BuildingMaterials.h"


BuildingMaterials::BuildingMaterials(string name, int price, string color, date_ expDate, string type)
	:Product(name, price, color, expDate)
{
	this->type = type;
}

void BuildingMaterials::setType(string type)
{
	this->type = type;
}

void BuildingMaterials::info() const
{
	Product::info();
	cout << "Type of office supply: " << type << endl;
}

bool BuildingMaterials::criticalDaysToExpiration() const
{
	if (daysToDateFromCurrDate(this->getExpDate()) <= 30)
	{
		
		return true;
	}
	return false;
}

string BuildingMaterials::getStringFileInfo() const
{
	string res = Product::getStringFileInfo();
	res += type;
	res += ';';
	return res;
}

void BuildingMaterials::readStringInfo(string & res)
{
	Product::readStringInfo(res);

	type = res[res.size() - 2];
}
