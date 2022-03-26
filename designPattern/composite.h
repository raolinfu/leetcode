#include <string>
#include <vector>
#include <iostream>
using namespace std;

#ifndef COMPOSITE_H
#define COMPOSITE_H
#endif

class Corp {
	private:
		string name;
		int salary;
	public:
		Corp(string n, int s): name(n), salary(s) {};
		virtual ~Corp() = default;
		virtual void showInfo();
};

class Manager: public Corp{
	private:
		vector<Corp*> children;
	public:
		Manager(string n, int s): Corp(n, s){};
		void addChild(Corp* sub);
		vector<Corp*> getChildren();
		void showAll();
};

class Common: public Corp{
	public:
		Common(string n, int s): Corp(n, s){};
};
