#include "customer.h"
#include <iomanip>
customer::customer() {
}

customer::~customer() {
}

void customer::setId(int ID) {
	this->id = ID;
}

void customer::setName(string NAME) {
	this->name = NAME;
}

void customer::setCmnd(string CMND) {
	this->cmnd = CMND;
}

void customer::setDate(dayofbirth DATE) {
	this->date = DATE;
}

void customer::setAddress(string ADDRESS) {
	this->address = ADDRESS;
}

void customer::setCustomer(int ID, string NAME, string CMND, int DAY, int MONTH, int YEAR, string ADDRESS) {
	this->id = ID;
	this->name = NAME;
	this->cmnd = CMND;
	date.setDate(DAY, MONTH, YEAR);
	this->address = ADDRESS;
}


void customer::input() {
	srand(time(NULL)); //cài đặt ID ngẫu nhiên
	id = rand();
	while (getchar() != '\n');
	cout << "\n\t\tNhap ho ten: ";
	getline(cin, name);
	cout << "\n\t\tNhap CMND: ";
	getline(cin, cmnd);
	date.input();
	cin.ignore();
	cout << "\n\t\tNhap dia chi: ";
	getline(cin, address);
}

void customer::output() {
	cout << "\n\t\t" << left << setw(8) << ++stt;
	cout << left << setw(10) << id;
	cout << left << setw(30) << name;
	cout << left << setw(20) << cmnd;
	date.output();
	cout << left << setw(30) << address;
}

void customer::savefile(ofstream &fileout) {
	fileout << id << ", ";
	fileout << name << ", ";
	fileout << cmnd << ", ";
	fileout << date.getDay() << "/";
	fileout << date.getMonth() << "/";
	fileout << date.getYear() << ", ";
	fileout << address << ", ";
}

void customer::readfile(ifstream &filein) {
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
	this->setCustomer(ID, NAME, CMND, DAY, MONTH, YEAR, ADDRESS);
}