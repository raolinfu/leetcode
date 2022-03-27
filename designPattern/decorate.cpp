#include "decorate.h"

Decorate1::Decorate1(Component* com) {
	this->component = com;
}

void Decorate1::doSomething() {
	cout<< "decorate1"<< endl;
	component->doSomething();
}

Decorate2::Decorate2(Component* com) {
	this->component = com;
}

void Decorate2::doSomething() {
	cout<< "decorate2"<< endl;
	component->doSomething();
}

int main() {
	ConcreteComponent concreteComponent;
	Decorate1 dec1(&concreteComponent);
	Decorate2 dec2(&dec1);
	dec2.doSomething();

	return 0;
}
