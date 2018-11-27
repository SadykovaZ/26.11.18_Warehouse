#include "Date.h"
//date_::date_()
//{
//	day = 1;
//	month = 1;
//	year = 1900;
//}
date_::date_(int day, int month , int year )
{
	setDay(day);
	setMonth(month);
	setYear(year);
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
void date_::print() const
{
	if (day < 10)	cout << 0;
	cout << day << ".";
	if (month < 10)	cout << 0;
	cout << month << "." << year;
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

int daysBetweenDates(const date_ & a, const date_ & b)
{
	int counDays = 0;
	int x = b.getYear(), y = a.getYear();
	int n = b.getMonth(), m = a.getMonth();
	counDays += b.getDay();

	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
		counDays += 31 - a.getDay();
	if (m == 4 || m == 6 || m == 9 || m == 11)
		counDays += 30 - a.getDay();
	if (m == 2) {
		if (a.getYear() % 400 == 0 || (a.getYear() % 4 == 0 && a.getYear() % 100 != 0))
			counDays += 29 - a.getDay();
		else
			counDays += 28 - a.getDay();
	}

	if (x > y) {
		x = x - 1;
		while (x != y) {
			if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
				counDays += 366;
			else
				counDays += 365;
			x--;
		}

			
		n = n - 1;
		while (n != 0) {
			if (n == 1 || n == 3 || n == 5 || n == 7 || n == 8 || n == 10)
				counDays += 31;
			if (n == 4 || n == 6 || n == 9 || n == 11)
				counDays += 30;
			if (n == 2) {
				if (b.getYear() % 400 == 0 || (b.getYear() % 4 == 0 && b.getYear() % 100 != 0))
					counDays += 29;
				else
					counDays += 28;
			}
			n--;
		}
			
		m = m + 1;
		while (m < 13) {
			if (m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
				counDays += 31;
			if (m == 4 || m == 6 || m == 9 || m == 11)
				counDays += 30;
			if (m == 2) {
				if (a.getYear() % 400 == 0 || (a.getYear() % 4 == 0 && a.getYear() % 100 != 0))
					counDays += 29;
				else
					counDays += 28;
			}
			m++;
		}
	}
	else if (x == y) {
		if (n > m) {
			n--;
			while (n != m) {
				if (n == 3 || n == 5 || n == 7 || n == 8 || n == 10)
					counDays += 31;
				if (n == 4 || n == 6 || n == 9 || n == 11)
					counDays += 30;
				if (n == 2) {
					if (x % 400 == 0 || (x % 4 == 0 && x % 100 != 0))
						counDays += 29;
					else
						counDays += 28;
				}
				n--;
			}
		}
		else if (n < m) {
			counDays = -1;
		}
	}
	else {
		counDays = -1;
	}
	return counDays;
}

int daysToDateFromCurrDate(const date_ & a)
{
	time_t t = time(0);
	struct tm now;
	localtime_s(&now, &t);
	now.tm_sec;
	int day = now.tm_mday;
	int month = (now.tm_mon + 1);
	int year = (now.tm_year + 1900);
	date_ currDay(day, month, year);
	return daysBetweenDates(currDay, a);
}
