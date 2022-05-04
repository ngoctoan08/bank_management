#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
using namespace std;
class deposit : public transaction
{
public:
	deposit(); //ham khoi tao
	~deposit(); //ham huy
	void displaytransaction(); //hiện thị thông tin giao dịch nạp tiền
	void savefile(ofstream &fileout); //ghi file
};

