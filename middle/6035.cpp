#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    long long numberOfWays(string s) {
        long long ans = 0;
        int n = s.length();
        if (n < 3)
            return 0;
        vector<int> left0(n);
        vector<int> left1(n);
        vector<int> right0(n);
        vector<int> right1(n);
        int zero = 0;
        int one = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                zero++;
                left0[i] = zero;
                left1[i] = one;
            } else {
                one++;
                left1[i] = one;
                left0[i] = zero;
            }
        }

        zero = 0;
        one = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == '0') {
                zero++;
                right0[i] = zero;
                right1[i] = one;
            } else {
                one++;
                right1[i] = one;
                right0[i] = zero;
            }
        }
        for (int i = 1; i < n - 1; i++) {
            if (s[i] == '0') {
                ans += (long long) left1[i - 1] * (long long) right1[i + 1];
            } else {
                ans += (long long) left0[i - 1] * (long long) right0[i + 1];
            }
        }
        
        return ans;
    }

    // 回溯法 超时
    long long numberOfWays1(string s) {
        long long ans = 0;
        string tmp;
        backtrace(s, tmp, ans, 0);    
        return ans;
    }

    void backtrace(string& s, string& tmp, long long& ans, int idx) {
        if (tmp.length() == 3) {
            ans++;
            return;
        }

        for (int i = idx; i < s.length(); i++) {
            if (tmp.empty() || s[i] != tmp.back()) {
                tmp.push_back(s[i]);
                backtrace(s, tmp, ans, i + 1);
                tmp.pop_back();
            }
        }
    }
};
