#include "MyDate.h"
/*Validation Functions: get the value they are testing and other values that helps them.
Returns whether the value is correct or not. We added them to help the set functions and other function later.*/
bool MyDate::isValidDay(const int day, const int month) const
{
	if ((month == 2))
	{
		return ((day > 0) && (day < 29));
	}
	else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		return ((day > 0) && (day < 31));
	}
	else if ((month > 0) && (month < 13))// the months that valid & left
	{
		return ((day > 0) && (day < 32));
	}
	return false;
}
bool MyDate::isValidMonth(const int month) const
{
	return ((month > 0) && (month < 13));
}
bool MyDate::isValidYear(const int year) const
{
	return (year > 0);
}

/*setters functions:  get the value that we want to set and other values that helps them.
update the day,month, year, comment and the date. in case of exeption, they initiate the date to 01.01.01.
this finctions doesnt return anything. at setComment we used with dinymic allocation. */
void MyDate::setDay(const int day, const int month)
{
	if (isValidDay(day, month))
		_day = day;
	else
		_day = 1;
}
void MyDate::setMonth(const int month)
{
	if (isValidMonth(month))
		_month = month;
	else
		_month = 1;
}
void MyDate::setYear(const int year)
{
	if (isValidYear(year))
		_year = year;
	else
		_year = 1;
}
void MyDate::setDate(const int day, const int month, const int year)
{
	setDay(day, month);
	setMonth(month);
	setYear(year);
}
void MyDate::setComment(const char* comment)
{
	if (comment == NULL) throw "ERROR! ";
	if (comment != NULL) delete this->getComment();
	this->_comment = new char[strlen(comment) + 1];
	strcpy_s(this->_comment, strlen(comment) + 1, comment);
}

/*getters: this functions get the day, month, year and allows access to the vars in the class.
they returns the variable they receive*/
int MyDate::getDay() const
{
	if (_day == NULL) return NULL;
	return this->_day;
}
int MyDate::getMonth() const
{
	if (_month == NULL) return NULL;
	return this->_month;
}
int MyDate::getYear() const
{
	if (_year == NULL) return NULL;
	return this->_year;
}

/*this function incement the day in the feild of "this" by 1 with the help of our
auxiliary function "shiftDatBy1". the function does not return any data. */
MyDate& MyDate::inc()
{
	this->shiftDate();
	return *this;
}

/*this function is a auxiliary function in order to increment the date by 1 day.
the function checking validation of the date and react accordingly, at the end of it proccess,
the date fo "this" is changing to the day after*/
void MyDate::shiftDate()
{
	_day++;
	if (!(isValidDay(_day, _month)))
	{
		_day = 1;
		_month++;
		if (!(isValidMonth(_month)))
		{
			_day = 1;
			_month = 1;
			_year++;
		}
	}
	print();
}

/*this function initiate the date in the feild of "this" to a default date-
the Date of submission of the assignment.  the function does not get or return any data*/
void MyDate::init()
{
	setDate(30, 8, 2020);
	print();
}

/*A Boolean function that works with the date in "this" field and with another date that it gets.
* the function checks if the date in the "this" field precede the date that the function receives
* and return true or false values.
*/
bool MyDate::isBefore(const MyDate& other)
{
	if (this->_year < other._year)
		return true;
	else if (this->_year > other._year)
		return false;
	else if (this->_month < other._month)// The years are equal
		return true;
	else if (this->_month > other._month)
		return false;
	else if (this->_day < other._day)// The years && the months are equal
		return true;
	else
		return false;
}

/*this function work with the date in "this" field, and print it.
In addition the function handles cases where the day of the month or year is single digits
and pads them with zeros if there is such a need.
*/
void MyDate::print() const
{
	std::cout << std::setfill('0') << std::setw(2) << _day << '/';
	std::cout << std::setfill('0') << std::setw(2) << _month << '/';
	std::cout << std::setfill('0') << std::setw(4) << _year << endl;
	if (_comment != NULL)
		cout << _comment << endl;
}

/*deafalt constractor: initialized to a default date that the task required of us.
*Also deals with an exception in which there is a date without a comment.
*/
MyDate::MyDate()
{
	this->setDate(1, 1, 2020);
	print();
	try
	{
		this->setComment(_comment);
	}
	catch (const char* comment)
	{
		cout << "No comment" << endl;
	}
}

/*constructor that receives data: receives year, month, day and note and initializes the date
Also deals with an exception in which there is a date without a comment.
*/
MyDate::MyDate(const char* comment, int day, int month, int year)
{
	try
	{
		this->setComment(comment);
	}
	catch (const char* comment)
	{
		cout << "No comment" << endl;
	}
	setDay(day, month);
	setMonth(month);
	setYear(year);
	print();
}

/* Copy constructor that receives date.
the copy constructor initiate the data that was not used with a dinymic allocation with inline method.
Also deals with an exception in which there is a date without a comment.
*/
MyDate::MyDate(const MyDate& other) :_day(other.getDay()), _month(other.getMonth()), _year(other.getYear())
{
	try
	{
		this->setComment(other.getComment());
	}
	catch (const char* comment)
	{
		cout << "No comment" << endl;
	}
	print();
}


/*distructor: delete the comment(the other feilds of the data will be
distroyed woh the help of the inviroment distructor)*/
MyDate::~MyDate()
{
	if (getComment() != NULL)
	{
		delete getComment();
	}
}
