#include <cctype>
#include <string>
#include <cstdlib>
#include <stack>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        stack<int> stk;
        char sign = '+';
        int n = 0;
        for (int i = 0; i < s.length(); i++) {
            if (std::isdigit(s[i])) {
                n = n * 10 + (s[i] - '0');
            }
            if ((!std::isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {
                int pre;
                switch(sign) {
                    case '+':
                        stk.push(n);
                        break;
                    case '-':
                        stk.push(-n);
                        break;
                    case '*':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre * n);
                        break;
                    case '/':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre / n);
                        break;
                }
                sign = s[i];
                n = 0;
            }
        }

        while (!stk.empty()) {
            ans += stk.top();
            stk.pop();
        }

        return ans;
    }
};
