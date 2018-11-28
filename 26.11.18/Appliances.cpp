#include "Appliances.h"
Appliances::Appliances(string name, int price, string color, date_ expDate, string purpose)
	:Product(name, price, color, expDate)
{
	this->purpose = purpose;
}
void Appliances::setPurpose(string purpose)
{
	this->purpose = purpose;
}
void Appliances::info() const
{
	Product::info();
	cout << "Purpose of appliance: " << getPurpose() << endl<<endl;
	cout << "------------------------------\n";
}
string Appliances::getStringFileInfo() const
{
	string res = Product::getStringFileInfo();
	res += purpose ;
	//res + ';';
	return res;
}

void Appliances::readStringInfo(string & res)
{
	Product::readStringInfo(res);
	
	purpose = res;
}


