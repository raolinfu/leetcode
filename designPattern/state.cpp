/* 
 * 状态模式
 * */
#include <iostream>
using namespace std;
class Context;

class State {
	public:
		virtual ~State() = 0;
		virtual void handle1() = 0;
		virtual void handle2() = 0;
		void setContext(Context* ctx) {
			this->ctx = ctx;
		}
	protected:
		Context* ctx;
};

class State1: public State {
	public:
		void handle1() {
			cout<< "stat1 handle1"<< endl;
		};
		void handle2() {
			this->ctx->setState(Context::st1);
			cout<< "stat1 handle2"<< endl;
		};
};

class State2: public State {
	public:
		void handle1() {
			cout<< "stat2 handle1"<< endl;
		};
		void handle2() {
			cout<< "stat2 handle2"<< endl;
		};
};

class Context {
	public:
		static State1 st1;
		static State2 st2;
		void setState(State* s) {
			this->state = s;
		}

		void handle1() {
			this->state->handle1();
		}

		void handle2() {
			this->state->handle1();
		}
	private:
		State* state;
};
