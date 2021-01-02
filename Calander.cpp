#include "Calander.h"
#include "Calander.h"
/*this function gets a num number and a MyDate expression, and initializes the date that
is in place of the num in the array with the MyDate expression it received
(if a date already exists there it overrides it).
* this function does not return any data.*/
void Calander::setDate(int num, const MyDate& other)
{
	if ((num < 0) || (num > ARR_SIZE)) throw "index is out of range";
	if (_dates[num] != NULL)
	{
		delete this->_dates[num];
		_numOfDates--;
	}
	this->_dates[num] = new MyDate(other);
	_numOfDates++;
}

/*this function gets a number between 1 and 30 and checks
if this place in the array is already full or not.
if the place is full - the function return false.*/
bool Calander::isFree(int index)
{
	index--;
	if ((index < 0) || (index > 29)) throw "index is out of range";
	if (!(this->_dates[index]))
		return true;// free
	else
		return false;// taken
}

//false is equal to -1, because 0 it's place in the array
/*This function returns the index of the first free place in the array. Returns false if the array is full
* this function does not receive any data.
*/
int Calander::firstFree()
{
	if (_numOfDates > 29)
		return -1;
	int count = 0;
	while (!(isFree(count + 1)))
	{
		count++;
	}
	return count;
}

/*This Boolian function Accepts MyDateand puts it in the first free space in the array,
if there is no free space it will return false.
*/
bool Calander::insert(MyDate& other)
{
	int free;
	free = this->firstFree();
	if (free == -1)
		return false;
	_numOfDates++;
	setDate(free, other);
	return true;
}

/*This function returns the index of the cell that has the earliest date.
* the function does not receive any data.
*/
int Calander::oldest()
{
	int count = 0;
	for (int i = 1; i < ARR_SIZE; i++)
	{
		if (_dates[i] != NULL)
			if (!_dates[count]->isBefore(*_dates[i]))
				count = i;
	}
	return count;
}

/*This funcation returns the number of cells that have a date
* the function does not receive any data.
*/
int Calander::datesNum()
{
	return _numOfDates;
}

/* This function Goes through all the members of the array and deletes them.
the function does not receive or return any data.
*/
void Calander::deleteAll()
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (_dates[i] != NULL)
		{
			delete1(i);
		}
	}
	_numOfDates = 0;
}

/*This function gets a int that represent an index in the array and deletes the member in the array
that its location is un the index place, if no date is found it will leave the member as NULL.
the function does not return any data.
*/
void Calander::delete1(const int num)
{
	if (_dates[num] != NULL)
	{
		delete this->_dates[num];
		this->_dates[num] = NULL;
		_numOfDates--;
	}
}

/*This function prints the members of the array, each member in a row is separated and the position of the member
in the array at the beginning of the line.
The method uses the print method in the MyDate class. If the array is empty,
the method should print "Empty Calander".
the function does not receive or return any data.*/
void Calander::printC()
{
	int count = 0;
	for (int i = 0; i < ARR_SIZE; i++)
	{
		if (isFree(i + 1) == true)
			count++;
		if (count == 29)
			cout << "Empty Calander" << endl;

		if (_dates[i] != NULL)
		{
			cout << "location = " << i << ": ";
			this->_dates[i]->print();
			cout << endl;
		}
	}
}

/*constructor that initializes all members of the array in NULL and the number of dates occupied by zero.*/
Calander::Calander()
{
	for (int i = 0; i < ARR_SIZE; i++)
	{
		_dates[i] = NULL;
	}
	_numOfDates = 0;
	printC();
}

/*copy constructor: goes on all the members of the array and copy them*/
Calander::Calander(const Calander& other)
{
	_numOfDates = other.getNumOfDate();
	for (int i = 0; i < ARR_SIZE; i++)
	{
		_dates[i] = other._dates[i];
	}
	printC();
}

/*distructor*/
Calander::~Calander()
{
	deleteAll();
}

