#include <condition_variable>
#include <unistd.h>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using namespace std;


class BlockQue {
private:
    mutex mtx;
    condition_variable cv;
    vector<int> caps;
    int n;
    int end = 0;
    int begin = 0;
public:
    BlockQue(int n): n(n + 1), caps(vector<int>(n + 1)) {};

    int take() {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() {
            return begin != end; 
        });

        int res = caps[begin];
        begin = (begin + 1) % n;
        cv.notify_all();
        return res;
    }

    void push(int num) {
        unique_lock<mutex> lock(mtx);
        cv.wait(lock, [this]() {
            return (end - begin + n) % n != n - 1; 
        });

        caps[end] = num;
        end = (end + 1) % n;
        cv.notify_all();
    }

    bool isEmpty() {
        unique_lock<mutex> lock(mtx);
        return begin == end;
    }

    bool isFull() {
        unique_lock<mutex> lock(mtx);
        return (end - begin + n) % n == n - 1;
    }

};

int main(int argc, char const *argv[])
{
    BlockQue bq(3);
    thread t1([&](){
        for (int i = 0; i < 100; i++) {
            sleep(1);
            bq.push(i);
        }
    });

    thread t2([&](){
        while (true)
        {
            int num = bq.take();
            cout<< num<< endl;
        }
    });

    t1.join();
    t2.join();
    return 0;
}
