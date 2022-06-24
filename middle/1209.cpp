#include <string>
#include <algorithm>
#include <stack>

using namespace std;
using pii = pair<char, int>;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        string ans;
        stack<pii> stk;
        int i = 0;
        int n = s.length();
        while (i < n) {
            if (!stk.empty()) {
                auto& top = stk.top();
                if (top.first == s[i]) {
                    if (top.second == k - 1)
                        stk.pop();
                    else
                        ++top.second;
                } else {
                    stk.push({s[i], 1});
                }
            } else {
                stk.push({s[i], 1});
            }
            i++;
        }

        while (!stk.empty()) {
            auto top = stk.top();
            ans += string(top.second, top.first);
            stk.pop();
        }

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
