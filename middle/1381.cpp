#include <vector>
using namespace std;

class CustomStack {
private:
    vector<int> stk;
    int cnt;
public:
    CustomStack(int maxSize) {
        cnt = maxSize;
    }
    
    void push(int x) {
        if (stk.size() < cnt)
            stk.push_back(x);
    }
    
    int pop() {
        int res;
        if (stk.empty()) {
            res = -1;
        } else {
            res = stk.back();
            stk.pop_back();
        }

        return res;
    }
    
    void increment(int k, int val) {
        int n = min(k, (int)stk.size());
        for (int i = 0; i < n; i++)
            stk[i] += val;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */