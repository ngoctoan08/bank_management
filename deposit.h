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
	float getDe_money();
	void addtransaction(string num);
	void displaytransaction();
};

