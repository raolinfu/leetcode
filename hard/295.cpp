#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> min_que;
    priority_queue<int, vector<int>, less<int>> max_que;
public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (max_que.empty()) {
            max_que.emplace(num);
            return;
        }
        if (max_que.size() == min_que.size()) {
            if (num <= min_que.top()) {
                max_que.emplace(num);
                return;
            }
            min_que.emplace(num);
            max_que.emplace(min_que.top());
            min_que.pop();
        } else {
            if (num >= max_que.top()) {
                min_que.push(num);
                return;
            }
            max_que.emplace(num);
            min_que.emplace(max_que.top());
            max_que.pop();
        }
    }
    
    double findMedian() {
        if (max_que.empty())
            return 0;
        if (max_que.size() == min_que.size())
            return (double)(max_que.top() + min_que.top()) / 2;
        else
            return max_que.top();
    }
};
