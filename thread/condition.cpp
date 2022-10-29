#include <condition_variable>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    mutex mtx;
    condition_variable cv;
    bool flag = false;

    auto fun = [&](int id) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [&]() { return flag;});

        cout<< "thread:"<< id<< endl;
    };

    thread t1(fun, 1);
    thread t2(fun, 2);

    sleep(1);
    {
        cout<< "set flag"<< endl;
        unique_lock<mutex> lock(mtx);
        flag = true;
        cv.notify_all();
    }

    t1.join();
    t2.join();
    return 0;
}

