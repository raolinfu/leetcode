#include <iostream>
using namespace std;

class Visitor;

class Employee {
	public:
		virtual int getSalary() = 0;
		virtual int getAge() = 0;
		virtual void accept(Visitor* visitor) = 0;
};

class Manager: public Employee {
	private:
		int salary;
		int age;
	public:
		Manager(int s, int a): salary(s), age(a){};
		int getSalary();
		int getAge();
		void accept(Visitor* visitor);
};

class Employer: public Employee {
	private:
		int salary;
		int age;
	public:
		Employer(int s, int a): salary(s), age(a){};
		int getSalary();
		int getAge();
		void accept(Visitor* visitor);
};

class Visitor {
	public:
		virtual void visit(Manager* manager) = 0;
		virtual void visit(Employer* employer) = 0;
};

class CommonVisitor: public Visitor {
	public:
		void visit(Manager* manager);
		void visit(Employer* employer);
};

