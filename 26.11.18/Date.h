#pragma once
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>
using namespace std;
class date_
{
	int day;
	int month;
	int year;
	
public:
	//date_();
	date_(int day=1, int month=1, int year=1900 );

	void setDay(int day);
	void setMonth(int month);
	void setYear(int year);

	void setDate(int day, int month, int year);

	int getDay() const { return day; }
	int getMonth() const { return month; }
	int getYear() const { return year; }

	void print() const;

	date_(const date_ &obj);

	date_ &operator=(const date_&obj);

	date_(date_&&obj);
	date_ & operator=(date_&&obj);

	date_&operator+=(const date_&obj);
	date_&operator-=(const date_&obj);
	date_&operator*=(const date_&obj);
	date_&operator/=(const date_&obj);

	date_ &operator+=(int number);
	date_ &operator-=(int number);
	date_ &operator*=(int number);
	date_ &operator/=(int number);

	date_ &operator++();
	date_ operator++(int);

	operator int();
	
};

ostream & operator<<(ostream& os, const date_ & obj);
istream & operator>>(istream & is, date_ & obj);

bool operator>(const date_&d, const date_&m);
bool operator>= (const date_&d, const date_&m);
bool operator<(const date_&d, const date_&m);
bool operator<=(const date_&d, const date_&m);
bool operator==(const date_&d, const date_&m);
bool operator!=(const date_&d, const date_&m);

date_ operator+(const date_&d, const date_&d1);
date_ operator+(const date_&d, int number);

date_ operator-(const date_&d, const date_&d1);
date_ operator-(const date_&d, int number);

date_ operator*(const date_&d, const date_&d1);
date_ operator*(const date_&d, int number);

date_ operator/(const date_&d, const date_&d1);
date_ operator/(const date_&d, int number);

int daysBetweenDates(const date_&a, const date_&b);
int daysToDateFromCurrDate(const date_&a);