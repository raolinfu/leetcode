#include "observe.h"

int main() {
	Subject* subject = new ConcreteSubject();
	Observer* ob1 = new ConcreteObserve1();
	Observer* ob2 = new ConcreteObserve2();
	subject->attach(ob1);
	subject->attach(ob2);
	string str = "hello";
	subject->notify(str);

	subject->dettach(ob1);
	subject->notify(str);

	subject->attach(ob1);
	subject->notify(str);
	delete subject;
	delete ob1;
	delete ob2;
	return 0;
}
