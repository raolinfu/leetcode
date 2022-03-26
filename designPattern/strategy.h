#include <iostream>
using namespace std;
#ifndef STATEGY_H
#define STATEGY_H
class Strategy {
	public:
		virtual void doSomething() = 0;
};

class Strategy1: public Strategy {
	public:
		void doSomething() {
			cout<< "Strategy1"<< endl;
		};
};

class Strategy2: public Strategy {
	public:
		void doSomething() {
			cout<< "Strategy2"<< endl;
		};
};

class Context {
	public:
		Context(Strategy* str): strategy(str) {};
		void doAnything() {
			strategy->doSomething();
		};
	private:
		Strategy* strategy;
};

#endif
