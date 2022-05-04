#pragma once
#include "account.h"
#include <iomanip> 
account::account()
{
}

account::~account()
{
}

void account::input() {
	customer::input();
	cout << "\n\t\tNhap STK cua ban: ";
	getline(cin, numac);
	this->money = 0;
}

void account::output() {
	customer::output();
	cout << left << setw(10) << numac;
	cout << left << setw(15) << (size_t)money;
	cout << "\n\t\t_______________________________________________________________________________________________________________________________________\n";
}

string account::getNumac() {
	return numac;
}

float account::getMoney() {
	return money;
}

void account::setAccount(string NUMAC, float MONEY) {
	this->numac = NUMAC;
	this->money = MONEY;
}

void account::ac_withdraw() {
	withdraw* wd = new withdraw;
	wd->addtransaction(numac);
	if (money > wd->getTs_money()) { //kiểm tra số dư có đủ tiền để rút không?
		this->money -= wd->getTs_money();
		arr_wd.push_back(wd); //thêm vào danh sách rút tiền
		cout << "\n\t\tRut tien thanh cong";
		//wd.savefile(fileout);
	}
	else
	{
		cout << "\n\t\tTai khoan khong du tien";
	}
}

void account::ac_deposit() {
	deposit* de = new deposit;
	de->addtransaction(numac);
	this->money += de->getTs_money();
	arr_de.push_back(de); //thêm vào danh sách nạp tiền
	cout << "\n\t\tNap tien thanh cong";
	//de->savedeposit();
}

void titletransaction() {
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
	cout << "\n\t\t" << left << setw(20) << "STK";
	cout << left << setw(30) << "SO TIEN";
	cout << left << setw(40) << "GHI CHU";
	cout << "THOI GIAN" << endl;
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
}

void account::ac_history() { //lịch sử giao dịch
	titletransaction();
	for (int i = 0; i < arr_de.size(); i++)
	{
		arr_de[i]->displaytransaction(); //danh sách tt nạp tiền
	}
	for (int i = 0; i < arr_wd.size(); i++)
	{
		arr_wd[i]->displaytransaction(); //ds tt rút tiền
	}
}

void account::ac_modify() { //thay đổi thông tin tài khoản
	string newname;
	string newcmnd;
	dayofbirth newdate;
	string newaddress;
	while (getchar() != '\n');
	cout << "\n\t\tNhap ho ten: ";
	getline(cin, newname);
	cout << "\n\t\tNhap CMND: ";
	getline(cin, newcmnd);
	newdate.input();
	cin.ignore();
	cout << "\n\t\tNhap dia chi: ";
	getline(cin, newaddress);
	customer::setName(newname);
	customer::setCmnd(newcmnd);
	customer::setDate(newdate);
	customer::setAddress(newaddress);
}

void account::savefile(ofstream &fileout) {
	customer::savefile(fileout);//kế thừa từ class customer
	fileout << numac << ", ";
	fileout << (size_t)money << "\n";
	fileout << arr_de.size() << "\n";
	for (int i = 0; i < arr_de.size(); i++)
	{
		arr_de[i]->savefile(fileout);
	}
	fileout << arr_wd.size() << "\n";
	for (int i = 0; i < arr_wd.size(); i++)
	{
		arr_wd[i]->savefile(fileout);
	}
}

////doc file thong tin tai khoan
void account::readaccount(ifstream &filein) {
	customer::readfile(filein);
	string NUMAC;
	float MONEY;
	string temp;
	if (getline(filein, NUMAC, ','))
		filein.seekg(1, 1);
	else
		return;
	if (filein >> MONEY) {}
	else
		return;
	if (getline(filein, temp)) {}
	else
		return;
	this->setAccount(NUMAC, MONEY);
}
//
void account::readdeposit(ifstream &filein) { //doc tt nap tien
	int n;
	filein >> n;
	string temp;
	getline(filein, temp);
	for (int i = 0; i < n; i++)
	{
		deposit* de = new deposit;
		de->readfile(filein);
		arr_de.push_back(de);
	}
}

void account::readwithdraw(ifstream &filein) { //doc tt rut tien
	int n;
	filein >> n;
	string temp;
	getline(filein, temp);
	for (int i = 0; i < n; i++)
	{
		withdraw* wd = new withdraw;
		wd->readfile(filein);
		arr_wd.push_back(wd);
	}
}

