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
	virtual string getTs_num();
	virtual float getTs_money();
	virtual void addtransaction(string num);
	void datetransaction(); //ham thoi gian
	void savefile(ofstream &fileout);
	void readfile(ifstream& filein);
};

