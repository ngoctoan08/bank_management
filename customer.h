#pragma once
#include <iostream>
#include <string>
#include "dayofbirth.h"
#include <cstdlib> //thu vien ham rand
#include <ctime> //thu vien time
#include <fstream>
using namespace std;
class customer
{
protected:
	int id;
	string name;
	string cmnd;
	dayofbirth date;
	string address;
public:
	int stt = 0; //so thu tu
	customer();
	~customer();
	void setId(int ID);
	void setName(string NAME); //dung de thay doi thong tin tai khoan
	void setCmnd(string CMND);
	void setDate(dayofbirth DATE);
	void setAddress(string ADDRESS);
	void input(); //nhap thong tin
	void output(); //xuat thong tin
	void savefile(ofstream& fileout); //ghi file
	void readfile(ifstream&); //phuong thuc doc file
};

