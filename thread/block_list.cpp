#include <list>
#include <unistd.h>
#include <iostream>
#include <mutex>

using namespace std;

class BlockList {
private:
    list<int> li;
    mutex mtx;
public:
    void put(int num) {
        unique_lock<mutex> lock(mtx);
        li.push_back(num);
    }

    int take() {
        mtx.lock();
        while (li.empty())
        {
        }
    }
};