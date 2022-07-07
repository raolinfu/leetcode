#include <unordered_map>
#include <functional>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MinStack {
    std::priority_queue<int, vector<int>, greater<int>> priq;
    stack<int> stk;
    unordered_map<int, int> mp;
public:
    MinStack() {

    }
    
    void push(int val) {
        stk.push(val);
        priq.push(val);
    }
    
    void pop() {
        int t = stk.top();
        stk.pop();
        ++mp[t];
        while (mp[priq.top()]) {
            --mp[priq.top()];
            if (mp[priq.top()] == 0) {
                mp.erase(priq.top());
            }

            priq.pop();
        }
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return priq.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
