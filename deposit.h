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
	void addtransaction(string num);
	void displaytransaction(); //ham hien thi thong tin nap tien
};

