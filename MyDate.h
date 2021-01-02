#pragma once
#include <iostream>
#include "MyDate.h"
#include <string>
#include <iomanip>

using namespace std;

class MyDate
{
private:
	int _day;
	int _month;
	int _year;
	char* _comment;
	bool isValidDay(const int day, const int month) const;
	bool isValidMonth(const int month)const;
	bool isValidYear(const int year)const;

public:
	//setters
	void setDay(const int day, const int month);
	void setMonth(const int month);
	void setYear(const int year);
	void setDate(const int day, const int month, const int year);
	void setComment(const char* comment);
	//getters
	int getDay() const;
	int getMonth() const;
	int getYear() const;
	char* getComment() const { return this->_comment; }
	//functions
	MyDate& inc();
	void shiftDate();
	void init();
	bool isBefore(const MyDate& other);
	void print() const;
	//constructors
	MyDate();
	MyDate(const char* comment, int day = 1, int month = 1, int year = 2020);
	MyDate(const MyDate& other);
	~MyDate();
};

