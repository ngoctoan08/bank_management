#pragma once
#include "account.h"
#include <vector>
#include <iostream>

using namespace std;
class arr_account
{
private:
	vector <account*> arr_ac;

public:
	arr_account();
	~arr_account();
	void input();
	void output();
	void addwithdraw(); //thêm gd rút tiền
	void adddeposit(); //thêm gd nạp tiền
	void displayhistory();  //kiểm tra lịch sử giao dịch
	void deleteaccount(); //xóa tài khoản
	void searchaccount(); //tìm kiếm tài khoản bằng STK 
	void modifyaccount(); //sửa đổi tt tài khoản bằng STK
	void savefile();
	void readfile(); //đọc tt 
};

