#include "controller.h"
controller::controller() {
	x = new arr_account;
}

controller::~controller(){
	delete x;
}

void controller::login() {
	string username;
	string password;
	cout << "\n\t\t=======WELCOME=======\n";
	cout << "\n\t\t=======LOGIN=======\n";
	do
	{
		cout << "\n\t\tNhap tai khoan: ";
		getline(cin, username);
		cout << "\n\t\tNhap mat khau: ";
		getline(cin, password);
		if (username == "admin" && password == "toan")
		{
			cout << "\n\t\tDang nhap thanh cong";
		}
		else
		{
			cout << "\n\t\tDang nhap that bai";
		}
	} while (username != "admin" || password != "toan");
}

void controller::PressAnyKey() {
	cout << "\n\t\tNhap phim bat ky";
	system("pause");
	system("cls");
}

void controller::menu() {
	while (true)
	{
		system("cls");
		cout << "\n\t\t============MENU============\n";
		cout << "\n\t\t01. Tao tai khoan" << endl;
		cout << "\n\t\t02. Nap tien" << endl;
		cout << "\n\t\t03. Rut tien" << endl;
		cout << "\n\t\t04. Lich su giao dich" << endl;
		cout << "\n\t\t05. Danh sach cac tai khoan" << endl;
		cout << "\n\t\t06. Tim kiem theo STK" << endl;
		cout << "\n\t\t07. Sua thong tin tai khoan" << endl;
		cout << "\n\t\t08. Xoa tai khoan" << endl;
		cout << "\n\t\t09. Ghi file" << endl;
		cout << "\n\t\t10. Doc file" << endl;
		cout << "\n\t\t00. Dang xuat" << endl;
		cout << "\n\t\t============================";
		int choice;
		cout << "\n\t\t Moi ban nhap (0 - 10): ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			x->input();
			PressAnyKey();
			break;
		case 2:
			cout << "\n\t\t02. Nap tien" << endl;
			x->adddeposit();
			PressAnyKey();
			break;
		case 3:
			cout << "\n\t\t03. Rut tien" << endl;
			x->addwithdraw();
			PressAnyKey();
			break;
		case 4:
			cout << "\n\t\t04. Lich su giao dich" << endl;
			x->displayhistory();
			PressAnyKey();
			break;
		case 5:
			cout << "\n\t\t05. Danh sach cac tai khoan" << endl;
			x->output();
			PressAnyKey();
			break;
		case 6:
			cout << "\n\t\t06. Tim kiem theo STK" << endl;
			x->searchaccount();
			PressAnyKey();
			break;
		case 7:
			cout << "\n\t\t07. Sua thong tin tai khoan" << endl;
			x->modifyaccount();
			PressAnyKey();
			break;
		case 8:
			cout << "\n\t\t08. Xoa tai khoan" << endl;
			x->deleteaccount();
			PressAnyKey();
			break;
		case 9:
			cout << "\n\t\t09. Ghi file" << endl;
			x->savefile();
			cout << "\n\t\tGhi file thanh cong" << endl;
			PressAnyKey();
			break;
		case 10:
			cout << "\n\t\t10. Doc file" << endl;
			x->readfile();
			cout << "\n\t\tDoc file thanh cong" << endl;
			PressAnyKey();
			break;
		case 0:
			cout << "\n\t\tDang xuat thanh cong" << endl;
			return;
			break;
		default:
			cout << "\n\t\t Khong hop le";
			PressAnyKey();
			break;
		}
	}
}

void controller::start() {
	controller::login();
	controller::PressAnyKey();
	controller::menu();
}