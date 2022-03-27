#include <iostream>
using namespace std;

#ifndef TEMPLATE_H
#define TEMPLATE_H
class Car {
	public:
		virtual void start() = 0;
		virtual void stop() = 0;
		virtual void alarm() = 0;
		virtual void run() {
			start();
			alarm();
			stop();
		};
};

class Benz: public Car {
	public:
		void start() {
			cout<< "benz start"<< endl;
		}

		void stop() {
			cout<< "benz stop"<< endl;
		}

		void alarm() {
			cout<< "benz alarm"<< endl;
		}
};

class Baoma: public Car {
	public:
		void start() {
			cout<< "baoma start"<< endl;
		}

		void stop() {
			cout<< "baoma stop"<< endl;
		}

		void alarm() {
			cout<< "baoma alarm"<< endl;
		}
};

#endif
