#include <stack>
using namespace std;

class Solution {
public:
    int lastRemaining(int n) {
        stack<int> stk1;
        stack<int> stk2;
        // bool flag = true;
        for (int i = n; i > 0; i--)
            stk1.emplace(1);

        while (stk1.size() > 1 || stk2.size() > 1) {
            stack<int>& ref1 = stk1.size() > 1? stk1: stk2;
            stack<int>& ref2 = stk1.size() > 1? stk2: stk1;
            bool del = true;
            while (!ref1.empty()) {
                if (!del)
                    ref2.emplace(ref1.top());
                ref1.pop();
                del = !del;
            }
        }

        return stk1.empty()? stk2.top(): stk1.top();
    }
};
