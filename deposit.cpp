#include "deposit.h"
#include <iomanip>
deposit::deposit() {
}

deposit::~deposit() {
}

void deposit::addtransaction(string num) {
	this->ts_num = num; //gan so tai khoan can nap
	cout << "\n\t\tNhap so tien nap: ";
	cin >> ts_money;
	cin.ignore();
	cout << "\n\t\tNhap ghi chu: ";
	getline(cin, ts_note);
	datetransaction();
}

void deposit::displaytransaction() {
	cout << "\n\t\t" << left << setw(20) << ts_num << "+";
	cout << left << setw(30) << size_t(ts_money);
	cout << left << setw(40) << ts_note;
	cout << day << "/" << month << "/" << year;
	cout << " " << hour << ":" << min << ":" << sec;
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
}
