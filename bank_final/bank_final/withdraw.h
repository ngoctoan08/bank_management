#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "transaction.h"
using namespace std;
class withdraw : public transaction
{
public:
	withdraw(); //ham khoi tao
	~withdraw(); //ham huy
	void displaytransaction();
	void savefile(ofstream& fileout);
};

