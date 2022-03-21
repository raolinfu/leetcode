#include <string>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
		stack<int> stk;
		for (auto str: tokens) {
			if (str == "+") {
				int first = stk.top();
				stk.pop();
				int second = stk.top();
				stk.pop();
				stk.push(first + second);
			}
			else if (str == "-") {
				int first = stk.top();
				stk.pop();
				int second = stk.top();
				stk.pop();
				stk.push(second - first);
			}
			else if (str == "*") {
				int first = stk.top();
				stk.pop();
				int second = stk.top();
				stk.pop();
				stk.push(first * second);
			}
			else if (str == "/") {
				int first = stk.top();
				stk.pop();
				int second = stk.top();
				stk.pop();
				stk.push(second / first);
			}
			else {
				stk.push(stoi(str));
			}
		}

		return stk.top();
    }
};
