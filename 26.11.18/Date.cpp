#include "Date.h"

date_::date_(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);

	localtime_s(&now, &t);
}
void date_::setDay(int day)
{
	if (day < 1 || day>31)	day = 1;
	this->day = day;
}
void date_::setMonth(int month)
{

	if (month < 1 || month>12)
		month = 1;

	this->month = month;
}
void date_::setYear(int year)
{

	if (year < 1900)
		year = 1900;

	this->year = year;
}
void date_::setDate(int day, int month, int year)
{
	setDay(day);
	setMonth(month);
	setYear(year);
}
int date_::getCurrentDay() const
{
	return now.tm_mday;
	
}
int date_::getCurrentMonth() const
{
	return now.tm_mon + 1;
}
int date_::getCurrentYear() const
{
	return now.tm_year + 1900;
}
void date_::print() const
{
	if (day < 10)	cout << 0;
	cout << day << ".";
	if (month < 10)	cout << 0;
	cout << month << "." << year;
}

string date_::getStrInfo() const
{
	string str;
	str += to_string(getDay());
	str += ";";
	str += to_string(getMonth());
	str += ";";
	str += to_string(getYear());

	return str;
}

date_::date_(const date_ & obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}
date_ & date_::operator=(const date_ & obj)
{
	if (this == &obj) return *this;
	this->~date_();
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
	return *this;
}
date_::date_(date_ && obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;
}
date_ &  date_::operator=(date_ && obj)
{
	this->day = obj.day;
	this->month = obj.month;
	this->year = obj.year;

	return *this;
}

date_ & date_::operator+=(const date_ & obj)
{
	this->day += obj.day;
	this->month += obj.month;
	this->year += obj.year;
	if (this->day > 31)
		this->day = 1;

	if (this->month > 12)
		this->month = 1;

	return *this;
}

date_ & date_::operator-=(const date_ & obj)
{
	this->day -= obj.day;
	this->month -= obj.month;
	this->year -= obj.year;
	if (this->day < 1)
		this->day = 1;

	if (this->month < 1)
		this->month = 1;

	if (this->year < 1900)
		this->year = 1900;

	return *this;
}

date_ & date_::operator*=(const date_ & obj)
{
	this->day *= obj.day;
	this->month *= obj.month;
	this->year *= obj.year;
	if (this->day > 31)
		this->day = 1;

	if (this->month > 12)
		this->month = 1;

	return *this;
}

date_ & date_::operator/=(const date_ & obj)
{
	this->day /= obj.day;
	this->month /= obj.month;
	this->year /= obj.year;
	if (this->day < 1)
		this->day = 1;

	if (this->month < 1)
		this->month = 1;

	if (this->year < 1900)
		this->year = 1900;

	return *this;
}

date_ & date_::operator+=(int number)
{
	this->day += number;
	this->month += number;
	this->year += number;

	if (this->day > 31)
		this->day = 1;

	if (this->month > 12)
		this->month = 1;

	return *this;
}

date_ & date_::operator-=(int number)
{
	this->day -= number;
	this->month -= number;
	this->year -= number;
	if (this->day < 1)
		this->day = 1;

	if (this->month < 1)
		this->month = 1;

	if (this->year < 1900)
		this->year = 1900;

	return *this;
}

date_ & date_::operator*=(int number)
{
	this->day *= number;
	this->month *= number;
	this->year *= number;
	if (this->day > 31)
		this->day = 1;

	if (this->month > 12)
		this->month = 1;

	return *this;
}

date_ & date_::operator/=(int number)
{
	this->day /= number;
	this->month /= number;
	this->year /= number;
	if (this->day < 1)
		this->day = 1;

	if (this->month < 1)
		this->month = 1;

	if (this->year < 1900)
		this->year = 1900;

	return *this;
}
date_ & date_::operator++()
{
	this->day++;

	return *this;
}
date_ date_::operator++(int)
{
	date_ tmp(*this);
	tmp.day = this->day;
	(this->day)++;
	return tmp;
}


date_::operator int()
{
	return this->day;
	return this->month;
	return this->year;
}


ostream & operator<<(ostream & os, const date_ & obj)
{
	if (obj.getDay() < 10)
		os << 0;
	os << obj.getDay() << ".";

	if (obj.getMonth() < 10)
		os << 0;
	os << obj.getMonth() << ".";

	os << obj.getYear() << endl;
	return os;
}

istream & operator>>(istream & is, date_ & obj)
{
	int day;
	int month;
	int year;
	is >> day;
	is >> month;
	is >> year;
	obj.setDay(day);
	obj.setMonth(month);
	obj.setYear(year);
	return is;
}
bool operator>(const date_ & d, const date_ & m)
{
	return d.getDay() > m.getMonth();
}

bool operator>=(const date_ & d, const date_ & m)
{
	return d.getDay() >= m.getMonth();
}

bool operator<(const date_ & d, const date_ & m)
{
	return d.getDay() < m.getMonth();
}

bool operator<=(const date_ & d, const date_ & m)
{
	return d.getDay() <= m.getMonth();
}

bool operator==(const date_ & d, const date_ & m)
{
	return d.getDay() == m.getMonth();
}

bool operator!=(const date_ & d, const date_ & m)
{
	return d.getDay() != m.getMonth();
}

date_ operator+(const date_ & d, const date_ & d1)
{
	date_ tmp(d.getDay());
	tmp += d1.getDay();
	return tmp;
}

date_ operator+(const date_ & d, int number)
{
	date_ tmp(d.getDay());
	tmp += number;
	return tmp;
}

date_ operator-(const date_ & d, const date_ & d1)
{
	date_ tmp(d.getDay());
	tmp -= d1.getDay();
	return tmp;
}

date_ operator-(const date_ & d, int number)
{
	date_ tmp(d.getDay());
	tmp -= number;
	return tmp;
}

date_ operator*(const date_ & d, const date_ & d1)
{
	date_ tmp(d.getDay());
	tmp *= d1.getDay();
	return tmp;
}

date_ operator*(const date_ & d, int number)
{
	date_ tmp(d.getDay());
	tmp *= number;
	return tmp;
}

date_ operator/(const date_ & d, const date_ & d1)
{
	date_ tmp(d.getDay());
	tmp /= d1.getDay();
	return tmp;
}

date_ operator/(const date_ & d, int number)
{
	date_ tmp(d.getDay());
	tmp /= number;
	return tmp;
}

