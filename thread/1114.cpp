#include <functional>
#include <condition_variable>
#include <mutex>
using namespace std;

class Foo {
    mutex mtx;
    condition_variable cv;
    int k = 0;
public:
    Foo() {
        
    }

    void first(function<void()> printFirst) {
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        k = 1;
        cv.notify_all();
    }

    void second(function<void()> printSecond) {
        std::unique_lock<mutex> lk(mtx);
        cv.wait(lk, [this](){ return k == 1;});
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        k = 2;
        cv.notify_one();
    }

    void third(function<void()> printThird) {
        std::unique_lock<mutex> lk(mtx);
        cv.wait(lk, [this](){ return k == 2;});
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};