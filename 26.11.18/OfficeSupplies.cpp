#include "OfficeSupplies.h"

OfficeSupplies::OfficeSupplies(string name, int price, string color, date_ expDate, int count)
	:Product(name, price, color, expDate)
{
	this->count = count;
}
void OfficeSupplies::setCount(int count)
{
	this->count = count;
}
void OfficeSupplies::info() const
{
	Product::info();
	cout << "Count of office supply: " << count << endl<<endl;
	cout << "------------------------------\n";
}



string OfficeSupplies::getStringFileInfo() const
{
	string res = Product::getStringFileInfo();
	res += to_string(count);
	res += ';';
	return res;
}

void OfficeSupplies::readStringInfo(string & res)
{
	Product::readStringInfo(res);

	count = stoi(res.substr(0, res.find(';')));
}
