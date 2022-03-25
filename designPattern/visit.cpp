#include "visit.h"

int Manager::getAge() {
	return this->age;
}

int Manager::getSalary() {
	return this->salary;
}

void Manager::accept(Visitor* visitor) {
	visitor->visit(this);
}

int Employer::getAge() {
	return this->age;
}

int Employer::getSalary() {
	return this->salary;
}

void Employer::accept(Visitor* visitor) {
	visitor->visit(this);
}

void CommonVisitor::visit(Manager* manager) {
	cout<< manager->getAge()<< "\t"<< manager->getSalary()<< endl;
}

void CommonVisitor::visit(Employer* employer) {
	cout<< employer->getAge()<< "\t"<< employer->getSalary()<< endl;
}

int main() {
	Manager manager(3000, 23);
	Employer employer(4000, 28);
	CommonVisitor common_visitor;
	common_visitor.visit(&manager);
	common_visitor.visit(&employer);

	return 0;
}




