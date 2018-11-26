#include<iostream>
#include<string>
#include"Product.h"
using namespace std;
void main()
{
	Product p(25,"Lo", 12, 2, 2010);
	p.info();
	system("pause");
}
//
//class exeption_ {
//	string err;
//public:
//	exeption_(string err) {
//		this->err = err;
//	}
//	string what()const { return err; }
//};
//class Ourexception:public exception
//{
//	
//	int level;
//public:
//	Ourexception(const char*exp, int level)
//		:exception(exp)
//	{
//		this->level = level;
//	}
//	int getLevel() const { return level; }
//	void setLevel(int level) { this->level = level; }
//	const char* what() const override
//	{
//		string *res =new string( exception::what());
//		*res += " level: ";
//		*res += to_string(level);
//		return res->c_str();
//	}
//
//
//};
//void f()
//{
//	throw Ourexception("Something error", 100);
//}
//void main()
//{
//	/*Ourexception e("text", 71);
//	cout << e.what();*/
//	try 
//	{
//		f();
//		string s;
//		s.at(5);
//	}
//	catch (exception& e)
//	{
//		cout << e.what();
//		if (typeid(e) == typeid(Ourexception))
//		{
//			if(q.get)
//		}
//	}
//	system("pause");
//}
