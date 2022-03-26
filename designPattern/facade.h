#include <string>
#include <iostream>
using namespace std;

#ifndef FACADE_H
#define FACADE_H
class Letter {
	private:
		string content;
		string address;
	public:
		void writeContent(string str);
		void writeAddress(string str);
		void sendLetter();
};

class Facade {
	public:
		void process(string cnt, string addr);
};

#endif
