#include <stack>
using namespace std;

class SortedStack {
private:
    stack<int> stk;
    stack<int> tmp;
public:
    SortedStack() {

    }
    
    void push(int val) {
        while (!stk.empty() && stk.top() < val)
        {
            tmp.push(stk.top());
            stk.pop();
        }
        stk.push(val);

        while (!tmp.empty())
        {
            stk.push(tmp.top());
            tmp.pop();
        }

    }
    
    void pop() {
        if (!stk.empty())
            stk.pop();
    }
    
    int peek() {
        if (stk.empty())
            return -1;
        else
            return stk.top();
    }
    
    bool isEmpty() {
        return stk.empty();
    }
};
