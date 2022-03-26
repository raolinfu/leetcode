#include <string>
#include <vector>
#include <iostream>

using namespace std;

#ifndef OBSERVE_H
#define OBSERVE_H
class Observer {
	public:
		virtual void update(string& str) = 0;
		virtual ~Observer() = default;
};

class ConcreteObserve1 : public Observer {
	public:
		void update(string& str) {
			cout<< "observe1:"<< str<< endl;
		};
};

class ConcreteObserve2 : public Observer {
	public:
		void update(string& str) {
			cout<< "observe2:"<< str<< endl;
		};
};

class Subject {
	public:
		virtual void notify(string& str) = 0;
		virtual void attach(Observer* observer) = 0;
		virtual void dettach(Observer* observer) = 0;
		virtual ~Subject() = default;
};

class ConcreteSubject: public Subject {
	private:
		vector<Observer*> observers;
	public:
		void notify(string& str) {
			for (auto ob: observers) {
				ob->update(str);
			}
		};

		void attach(Observer* observer) {
			observers.push_back(observer);
		}

		void dettach(Observer* observer) {
			for (auto ob = observers.begin(); ob != observers.end(); ob++) {
				if (*ob == observer) {
					observers.erase(ob);
					return;
				}
			}
		}
};
#endif
