#pragma once
#include "account.h"
#include <vector>
#include <iostream>

using namespace std;
class arr_account
{
private:
	vector <account> arr_ac;
public:
	arr_account();
	~arr_account();
	void input();
	void output();
	void addwithdraw(); //ham rut tien
	void adddeposit(); //ham nap tien
	void displayhistory();  //ham kiem tra lich su giao dich
	void deleteaccount(); //ham xoa tai khoan
	void searchaccount(); //ham tim kiem 
	void modifyaccount(); //ham sua doi thong tin tai khoan
	void savefile(); //ghi file
	void readaccount(ifstream& filein);
	void readfile(); //doc file
};

