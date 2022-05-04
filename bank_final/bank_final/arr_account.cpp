#pragma once
#include "arr_account.h"
#include <iomanip> 
arr_account::arr_account() {
}

arr_account::~arr_account() {
}

void title() {
	cout << "\n\t\t_______________________________________________________________________________________________________________________________________\n";
	cout << "\n\t\t" << left << setw(8) << "STT";
	cout << left << setw(10) << "ID";
	cout << left << setw(30) << "HO TEN";
	cout << left << setw(20) << "CMND";
	cout << left << setw(15) << "NGAY SINH";
	cout << left << setw(30) << "DIA CHI";
	cout << left << setw(10) << "STK";
	cout << left << setw(15) << "SO DU";
	cout << "\n\t\t_______________________________________________________________________________________________________________________________________\n";
}

void arr_account::input() {
	account* a = new account;
	bool x = true;
	if (arr_ac.size() == 0) //tao tk dau tien
	{
		a->input();
		arr_ac.push_back(a);
		cout << "\n\t\tTao tai khoan thanh cong";
	}
	else
	{
		a->input(); //nhap tai khoan
		arr_ac.push_back(a);
		//loi tai khoan trung nhau 
		for (int i = 1; i < arr_ac.size(); i++) //size = 1
		{
			if (a->getNumac() == arr_ac[i - 1]->getNumac())
			{
				cout << "\n\t\tTai khoan da ton tai";
				arr_ac.pop_back();
				x = false;
			}
		}
		if (x == true)
		{
			cout << "\n\t\tTao tai khoan thanh cong";
		}
	}
}

void arr_account::output() {
	title();
	for (int i = 0; i < arr_ac.size(); i++)
	{
		arr_ac[i]->stt = i;
		arr_ac[i]->output();
	}
}


void arr_account::adddeposit() {
	string de_num;
	bool x = false;
	while (getchar() != '\n');
	cout << "\n\t\tNhap STK can nap tien: ";
	getline(cin, de_num);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		if (arr_ac[i]->getNumac() == de_num) {
			x = true;
			arr_ac[i]->ac_deposit();
		}
	}
	if (x == false)
	{
		cout << "\n\t\tSTK khong ton tai";
	}
}

void arr_account::addwithdraw() {
	string wd_num;
	bool x = false;
	while (getchar() != '\n');
	cout << "\n\t\tNhap STK can rut tien: ";
	getline(cin, wd_num);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		if (arr_ac[i]->getNumac() == wd_num) {
			x = true;
			arr_ac[i]->ac_withdraw();
		}
	}
	if (x == false)
	{
		cout << "\n\t\tSTK khong ton tai";
	}
}
//lich su giao dich
void arr_account::displayhistory() {
	string his_num;
	int index = 0;
	bool x = false;
	while (getchar() != '\n');
	cout << "\n\t\tNhap STK can kiem tra: ";
	getline(cin, his_num);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		if (his_num == arr_ac[i]->getNumac()) {
			x = true;
			index = i;
		}
	}
	if (x == true)
	{
		arr_ac[index]->ac_history();
	}
	else
	{
		cout << "\n\t\tSTK khong ton tai";
	}
}
//tim kiem tai khoan bang STK
void arr_account::searchaccount() {
	string se_num; //STK muon tim kiem
	int index = 0;
	bool x = false;
	while (getchar() != '\n');
	cout << "\n\t\tNhap STK muon tim kiem: ";
	getline(cin, se_num);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		if (arr_ac[i]->getNumac() == se_num) {
			index = i;
			x = true;
		}
	}
	if (x == true)
	{
		cout << "\n\n\t\tTHONG TIN TAI KHOAN" << endl;
		title();
		arr_ac[index]->stt = 0;
		arr_ac[index]->output();
		cout << "\n\n\t\tLICH SU GIAO DICH" << endl;
		arr_ac[index]->ac_history();
	}

	else
	{
		cout << "\n\t\tSTK khong ton tai";
	}
}

//xoa tai khoan
void arr_account::deleteaccount() {
	string dl_num; //STK muon xoa
	int index = 0;
	bool x = false;
	while (getchar() != '\n');
	cout << "\n\t\tNhap STK muon xoa: ";
	getline(cin, dl_num);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		if (arr_ac[i]->getNumac() == dl_num) {
			//index = i + 1; //vi tri xoa
			index = i;
			x = true;
		}
	}
	if (x == true)
	{
		//for (int i = index; i < arr_ac.size(); i++) 
		//{
		//	arr_ac[i-1] = arr_ac[i]; //fix loi chi so ngoai pham vi
		//}
		//arr_ac.pop_back(); //xoa phan tu cuoi
		arr_ac.erase(arr_ac.begin() + index);
		cout << "\n\t\tXoa thanh cong";
	}
	else
	{
		cout << "\n\t\tSTK khong ton tai";
	}
}
//sua thong tin tai khoan
void arr_account::modifyaccount() {
	string md_num;
	bool x = false;
	while (getchar() != '\n');
	cout << "\n\t\tNhap STK can thay doi: ";
	getline(cin, md_num);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		if (md_num == arr_ac[i]->getNumac()) {
			x = true;
			arr_ac[i]->ac_modify();
			cout << "\n\t\tCap nhat thong tin STK " << md_num << " thanh cong";
		}
	}
	if (x == false)
	{
		cout << "\n\t\tSTK khong ton tai";
	}
}

void arr_account::savefile() {
	ofstream fileout;
	fileout.open("thongtin.txt", ios::out);
	for (int i = 0; i < arr_ac.size(); i++)
	{
		arr_ac[i]->savefile(fileout);
	}
	fileout.close();
}

void arr_account::readfile() {
	ifstream filein;
	filein.open("thongtin.txt", ios::in);
	while (!filein.eof()) { //doc moi dong cuoi
		account* x = new account;
		int ID, DAY, MONTH, YEAR;
		string NAME, CMND, ADDRESS;
		if (filein >> ID)
			filein.seekg(2, 1); //dịch con trỏ sang phải 2 đơn vị
		else
			return;

		if (getline(filein, NAME, ','))
			filein.seekg(1, 1);
		else
			return;

		if (getline(filein, CMND, ',')) {}
		else
			return;

		if (filein >> DAY)
			filein.seekg(1, 1);
		else
			return;

		if (filein >> MONTH)
			filein.seekg(1, 1);
		else
			return;

		if (filein >> YEAR)
			filein.seekg(2, 1);
		else
			return;
		if (getline(filein, ADDRESS, ','))
			filein.seekg(1, 1);
		else
			return;
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
		x->setAccount(NUMAC, MONEY);
		x->setCustomer(ID, NAME, CMND, DAY, MONTH, YEAR, ADDRESS);
		x->readdeposit(filein);
		x->readwithdraw(filein);
		arr_ac.push_back(x);		
	}
	filein.close();
}
