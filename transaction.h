#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <iomanip> //ham setw
using namespace std;
class transaction
{
protected:
	string ts_num;
	float ts_money;
	string ts_note;
	int day, month, year, hour, min, sec;
public:
	string getTs_num();
	float getTs_money();
	void addtransaction(string num);
	void datetransaction(); //ham thoi gian
	void readfile(ifstream& filein);
};

