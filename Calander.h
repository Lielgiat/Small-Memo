
#pragma once
#include <iostream>
#include "MyDate.h"
#include <string>
#include <iomanip>

	using namespace std;

#define ARR_SIZE 30

	class Calander
	{
	private:
		int _numOfDates = 0;
		MyDate* _dates[ARR_SIZE];

	public:
		//setter
		void setDate(int num, const MyDate& other);
		//getter
		int getNumOfDate() const { return _numOfDates; }
		//functions
		bool isFree(int index);
		int firstFree();
		bool insert(MyDate& other);

		int oldest();
		int datesNum();
		void deleteAll();
		void delete1(const int num);
		void printC();
		//constructors
		Calander();
		Calander(const Calander& other);
		~Calander();

		void operator=(MyDate other)
		{
			if (_numOfDates > 29)
				return;
			int count = 0;
			while (!isFree(count))
			{
				count++;
			}
			_dates[count] = &other;
		}
	};




