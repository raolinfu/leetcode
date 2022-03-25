#include "memo.h"
#include <iostream>
using namespace std;

void Originator1::restoreState(Memo1 memo1) {
	this->age = memo1.getAge();
	this->salary = memo1.getSalary();
}

Memo1 Originator1::createState() {
	return Memo1(this->age, this->salary);
}

int Memo1::getAge() { return this->age;}

int Memo1::getSalary() { return this->salary;}

void CareTaker::setMemoinfo(Memo1 m) { this->memo1 = m;}

Memo1 CareTaker::getMemoinfo() { return this->memo1;}

int main() {
	Originator1 orig(12, 300);
	CareTaker care;
	care.setMemoinfo(orig.createState());
	cout<< orig.getAge()<< "\t"<< orig.getSalary()<< endl;
	orig.setAge(24);
	orig.setSalary(1434);
	cout<< orig.getAge()<< "\t"<< orig.getSalary()<< endl;
	orig.restoreState(care.getMemoinfo());
	cout<< orig.getAge()<< "\t"<< orig.getSalary()<< endl;
	return 0;
}
