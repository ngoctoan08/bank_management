#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include "customer.h"
#include "withdraw.h"
#include "deposit.h"
#include "transaction.h"
using namespace std;

class account : public customer
{
private:
	string numac;
	float money;
	//khai bao 2 vector with va deposit
	//vector <withdraw> arr_wd; //danh sach thong tin nap tien
	//vector <deposit> arr_de; //danh sach thong tin rut tien
	//vector <transaction> arr_ts;
	vector <withdraw> arr_wd;
	vector <deposit> arr_de;
public:
	account();
	~account();
	//int stt = 0;
	void input();
	void output();
	string getNumac();
	float getMoney(); 
	void setMoney(float MONEY);
	void ac_withdraw(); //ham nap tien
	void ac_deposit(); //ham rut tien
	void ac_history(); //ham lich su chuyen tien
	void ac_modify(); //ham tha doi thong tin
	void readaccount(ifstream& filein);
	void readdeposit(ifstream& filein);
	void readwithdraw(ifstream& filein);
	void readfile(ifstream& filein);
	void saveaccount(ofstream& fileout);
	void savefile(ofstream &fileout);
	friend class arr_account;
};


