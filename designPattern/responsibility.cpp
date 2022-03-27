#include "responsibility.h"
#include <iostream>
using namespace std;

void Handler::doSomething(int type) {
	if (type == getLevel()) {
		this->response();
	} else {
		if (next_handler != nullptr) {
			next_handler->doSomething(type);
		}
	}
}

void Handler::setNextHandler(Handler* next) {
	this->next_handler = next;
}

void Father::response() {
		cout<< "type1 Father do somthing"<< endl;
}

void Husband::response() {
		cout<< "type2 Husband do somthing"<< endl;
}

void Son::response() {
		cout<< "type3 Son do somthing"<< endl;
}
int main() {
	Father fater;
	Husband husband;
	Son son;
	fater.setNextHandler(&husband);
	husband.setNextHandler(&son);
	fater.doSomething(1);
	fater.doSomething(3);
	fater.doSomething(2);
	return 0;
}
