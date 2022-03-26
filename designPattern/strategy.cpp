#include "strategy.h"

int main() {
	Strategy1 stra1;
	Strategy2 stra2;
	Context cnt(&stra1);
	cnt.doAnything();
	Context cnt1(&stra2);
	cnt1.doAnything();
	return 0;
}
