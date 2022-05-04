#include "deposit.h"
#include <iomanip>
deposit::deposit() {
}

deposit::~deposit() {
}

void deposit::displaytransaction() {
	cout << "\n\t\t" << left << setw(20) << ts_num << "+";
	cout << left << setw(30) << size_t(ts_money);
	cout << left << setw(40) << ts_note;
	cout << day << "/" << month << "/" << year;
	cout << " " << hour << ":" << min << ":" << sec;
	cout << "\n\t\t___________________________________________________________________________________________________________________________\n";
}

void deposit::savefile(ofstream& fileout) {
	fileout << ts_num << ", ";
	fileout << "+" << (size_t)ts_money << ", ";
	fileout << ts_note << ", ";
	fileout << day << "/";
	fileout << month << "/";
	fileout << year << " ";
	fileout << hour << ":";
	fileout << min << ":";
	fileout << sec << "\n";
}