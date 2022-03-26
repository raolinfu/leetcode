#include "facade.h"

void Letter::writeContent(string str) {
	cout<< "write content"<< endl;
	this->content = str;
}
void Letter::writeAddress(string str) {
	cout<< "write address"<< endl;
	this->address = str;
}
void Letter::sendLetter() {
	cout<< "send a letter"<< endl;
}

void Facade::process(string cnt, string addr) {
	Letter letter;
	letter.writeContent(cnt);
	letter.writeAddress(addr);
	letter.sendLetter();
}

int main() {
	Facade f;
	f.process("miss you", "1101");
	return 0;
}
