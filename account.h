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
	string numac; //so tai khoan
	float money; //so du
	vector <withdraw> arr_wd; // danh sach thong tin rut tien
	vector <deposit> arr_de; //danh sach thong tin nap tien
public:
	account();
	~account();
	void input();
	void output();
	string getNumac();
	float getMoney(); 
	void setMoney(float MONEY);
	void ac_withdraw(); //phương thức rút tiền
	void ac_deposit(); //phương thức nạp tiền
	void ac_history(); //lịch sử chuyển tiền
	void ac_modify(); //thay đổi thông tin
	void readaccount(ifstream& filein); //đọc thông tin tài khoản, kế thừa cả từ lớp customer
	void readdeposit(ifstream& filein); // đọc danh sách nạp tiền
	void readwithdraw(ifstream& filein); //đọc danh sách rút tiền
	void readfile(ifstream& filein); //đọc tất cả 
	void saveaccount(ofstream& fileout); //ghi file thông tin tài khoản
	void savefile(ofstream &fileout); //đọc file
	friend class arr_account;
};


