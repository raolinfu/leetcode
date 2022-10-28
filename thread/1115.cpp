#include <functional>
#include <mutex>
#include <condition_variable>
using namespace std;

class FooBar {
private:
    int n;
    int n1 = 0;
    int n2 = 0;
    mutex mtx;
    condition_variable cv;

public:
    FooBar(int n) {
        this->n = n;
    }

    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return n1 == n2;});
            
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            ++n1;
            cv.notify_one();
        }
    }

    void bar(function<void()> printBar) {
        
        for (int i = 0; i < n; i++) {
            std::unique_lock<mutex> lock(mtx);
            cv.wait(lock, [this]() { return n1 == n2 + 1;});
            
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            ++n2;
            cv.notify_one();
        }
    }
};