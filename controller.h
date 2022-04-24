#pragma once
#include "arr_account.h"
class controller
{
private:
	arr_account* x;
	void login();
	void menu();
	void PressAnyKey();
public:
	controller(); //ham khoi tao con tro
	~controller(); //ham huy
	void start();
};

