#ifndef RESPONSIBILITY_H
#define RESPONSIBILITY_H
class Handler {
	private:
		Handler* next_handler;
		int type;
	public:
		Handler(int t): type(t) {};
		virtual void doSomething(int type);
		virtual void setNextHandler(Handler* next);
		virtual int getLevel() {return type;};
		virtual void response() = 0;
};

class Father: public Handler {
	public:
		Father():Handler(1){};
		void response();
};

class Husband: public Handler {
	public:
		Husband(): Handler(2) {};
		void response();
};

class Son: public Handler {
	public:
		Son(): Handler(3) {};
		void response();
};
#endif
