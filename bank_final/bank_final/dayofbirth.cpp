#include "dayofbirth.h"
#include <iomanip>
dayofbirth::dayofbirth() {
}

dayofbirth::~dayofbirth() {
}

void dayofbirth::input() {
	cout << "\n\t\tNhap ngay sinh: ";
	do
	{
		cin >> day;
	} while (day <= 0 && day > 31);
	do
	{
		cin >> month;
	} while (month <= 0 && month > 12);
	do
	{
		cin >> year;
	} while (year <= 1900 && year > 2022);
}

void dayofbirth::output() {
	cout << dayofbirth::getDay() << "/" << dayofbirth::getMonth() << "/" << dayofbirth::getYear();
	cout << left << setw(7) << " ";
}

int dayofbirth::getDay() {
	return day;
}

int dayofbirth::getMonth() {
	return month;
}

int dayofbirth::getYear() {
	return year;
}

void dayofbirth::setDate(int DAY, int MONTH, int YEAR) {
	this->day = DAY;
	this->month = MONTH;
	this->year = YEAR;
}