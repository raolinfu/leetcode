#include <vector>
#include <cmath>
#include <string>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) {
        int ans = 0;
        string str = std::to_string(n);
        vector<int> prefix(str.length(), 0);
        vector<int> sufix(str.length(), 0);

        int len = str.length();
        for (int i = 0; i < str.length() - 1; i++) {
            string pre = str.substr(0, i);
            string suf = str.substr(i + 1);
            if (!pre.empty())
                prefix[i] = std::stoi(pre);
            if (!sufix.empty())
                sufix[i] = std::stoi(suf);
        }

        string s = str.substr(0, len - 1);
        if (!s.empty())
            prefix[len - 1] = std::stoi(s);

        for (int i = 0; i < str.length(); i++) {
            char ch = str[i];
            int tol = prefix[i] * pow(10, len - i - 1);
            if (ch == '0') {
            } else if (ch == '1') {
                tol += sufix[i] + 1;
            } else {
                tol += pow(10, len - i - 1);
            }
            ans += tol;
        }


        return ans;

    }
};
