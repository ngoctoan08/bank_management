#pragma once
#include <iostream>
using namespace std;
class dayofbirth
{
private:
	int day;
	int month;
	int year;
public:
	dayofbirth();
	~dayofbirth();
	void input();
	void output();
	int getDay();
	int getMonth();
	int getYear();
	void setDay(int DAY);
	void setMonth(int MONTH);
	void setYear(int YEAR);
};

