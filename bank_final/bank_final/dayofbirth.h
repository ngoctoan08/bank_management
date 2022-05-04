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
	void setDate(int DAY, int MONTH, int YEAR);
};

