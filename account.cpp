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

void account::setMoney(float MONEY) {
	this->money = MONEY;
}

void account::ac_withdraw() {
	/*transaction *ts;
	ts = new withdraw;*/
	/*transaction* ts = new withdraw;
	ts->addtransaction(numac);*/
	withdraw wd;
	wd.addtransaction(numac);
	if (money > wd.getTs_money()) { //ktra so du co du khong?
		this->money -= wd.getTs_money();
		//arr_ts.push_back(*ts);
		arr_wd.push_back(wd);
		cout << "\n\t\tRut tien thanh cong";
	}
	else
	{
		cout << "\n\t\tTai khoan khong du tien";
	}
}
	
void account::ac_deposit() {
	deposit de;
	de.addtransaction(numac);
	this->money += de.getTs_money();
	arr_de.push_back(de);
	cout << "\n\t\tNap tien thanh cong";
}

void titletransaction() {
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
	cout << "\n\t\t" << left << setw(20) << "STK";
	cout << left << setw(30) << "SO TIEN";
	cout << left << setw(40) << "GHI CHU";
	cout << "THOI GIAN" << endl;
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
}

void titlewithdraw() {
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
	cout << "\n\t\t" << left << setw(20) << "STK";
	cout << left << setw(30) << "SO TIEN RUT";
	cout << left << setw(40) << "GHI CHU";
	cout << "THOI GIAN" << endl;
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
}


void account::ac_history() {

	titletransaction();
	for (int i = 0; i < arr_de.size(); i++)
	{
		arr_de[i].displaytransaction();
	}
	for (int i = 0; i < arr_wd.size(); i++)
	{
		arr_wd[i].displaytransaction();
	}
}

void account::ac_modify() {
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

void account::saveaccount(ofstream& fileout) {
	customer::savefile(fileout);
	fileout << numac << ", ";
	fileout << (size_t)money << "\n";
}

void account::savefile(ofstream &fileout) {
	account::saveaccount(fileout);
	fileout << arr_de.size() << "\n";
	for (int i = 0; i < arr_de.size(); i++)
	{
		arr_de[i].savefile(fileout);
	}
	fileout << arr_wd.size() << "\n";
	for (int i = 0; i < arr_wd.size(); i++)
	{
		arr_wd[i].savefile(fileout);
	}
}


////doc file account
void account::readaccount(ifstream& filein) {
	customer::readfile(filein);
	getline(filein, numac, ',');
	filein.seekg(1, 1);
	filein >> this->money;
	string temp;
	getline(filein, temp);
}

void account::readdeposit(ifstream& filein) { //doc tt nap tien
	deposit de;
	int n; //sl nap tien
	filein >> n;
	string temp; //doc dau xuong dong
	getline(filein, temp);
	for (int i = 0; i < n; i++)
	{
		de.readfile(filein);
		arr_de.push_back(de);
	}	
}

void account::readwithdraw(ifstream& filein) { //doc tt rut tien
	withdraw wd;
	int n; //sl rut tien
	filein >> n;
	string temp; //doc ky tu xuong dong
	getline(filein, temp);
	for (int i = 0; i < n; i++)
	{
		wd.readfile(filein);
		arr_wd.push_back(wd);
	}
}

void account::readfile(ifstream& filein) { //doc tat ca
	account::readaccount(filein);
	account::readdeposit(filein);
	account::readwithdraw(filein);
}
