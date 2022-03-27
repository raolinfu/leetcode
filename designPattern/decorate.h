#include <iostream>
using namespace std;

#ifndef DECORATE_H
#define DECORATE_H
class Component {
	public:
		virtual void doSomething() = 0;
};

class ConcreteComponent: public Component {
	public:
		void doSomething() {
			cout<< "concrete Component"<< endl;
		}
};

class Decorate1: public Component {
	private:
		Component* component;
	public:
		Decorate1(Component* com);
		void doSomething();
};

class Decorate2: public Component {
	private:
		Component* component;
	public:
		Decorate2(Component* com);
		void doSomething();
};
#endif
