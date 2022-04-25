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

void customer::input() {
	srand(time(NULL)); //cai dat id ngau nhien
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

void customer::savefile(ofstream& fileout) {
	fileout << id << ", ";
	fileout << name << ", ";
	fileout << cmnd << ", ";
	fileout << date.getDay() << "/";
	fileout << date.getMonth() << "/";
	fileout << date.getYear() << ", ";
	fileout << address << ", ";
}

void customer::readfile(ifstream& filein) {
	filein >> this->id;
	filein.seekg(2, 1); //dich sang phai 2 don vi
	getline(filein, name, ',');
	filein.seekg(1, 1);
	getline(filein, cmnd, ',');
	int DAY, MONTH, YEAR;
	filein >> DAY;
	date.setDay(DAY);
	filein.seekg(1, 1);
	filein >> MONTH;
	date.setMonth(MONTH);
	filein.seekg(1, 1);
	filein >> YEAR;
	date.setYear(YEAR);
	filein.seekg(2, 1); 
	getline(filein, address, ',');
	filein.seekg(1, 1);
}