#include "transaction.h"
//transaction::transaction() {
//}
//
//transaction::~transaction() {
//}

string transaction::getTs_num(){
	return this->ts_num;
}

float transaction::getTs_money() {
	return this->ts_money;
}

void transaction::datetransaction() {
	time_t now;
	struct  tm nowLocal;
	now = time(NULL);
	localtime_s(&nowLocal, &now);
	day = nowLocal.tm_mday;
	month = nowLocal.tm_mon + 1;
	year = nowLocal.tm_year + 1900;
	hour = nowLocal.tm_hour;
	min = nowLocal.tm_min;
	sec = nowLocal.tm_sec;
}

void transaction::addtransaction(string num) {
	this->ts_num = num;
	cout << "\n\t\tNhap so tien: ";
	cin >> ts_money;
	cin.ignore();
	cout << "\n\t\tNhap ghi chu: ";
	getline(cin, ts_note);
	datetransaction();
}

void transaction::readfile(ifstream& filein) {
	getline(filein, ts_num, ',');
	filein.seekg(2, 1);
	filein >> this->ts_money;
	filein.seekg(2, 1);
	getline(filein, ts_note, ',');
	filein.seekg(1, 1);
	filein >> this->day;
	filein.seekg(1, 1);
	filein >> this->month;
	filein.seekg(1, 1);
	filein >> this->year;
	filein.seekg(1, 1);
	filein >> this->hour;
	filein.seekg(1, 1);
	filein >> this->min;
	filein.seekg(1, 1);
	filein >> this->sec;
	string temp;
	getline(filein, temp);
	//filein.seekg(1, 1);
}