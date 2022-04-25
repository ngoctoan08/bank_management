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
	void setId(int ID);  //các phương thức setter để thay đổi thông tin tài khoản
	void setName(string NAME);
	void setCmnd(string CMND);
	void setDate(dayofbirth DATE);
	void setAddress(string ADDRESS);
	void input(); //nhập thông tin
	void output(); //xuất thông tin
	void savefile(ofstream& fileout); //ghi file
	void readfile(ifstream&); //đọc file
};

