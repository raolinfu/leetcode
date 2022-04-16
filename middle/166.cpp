#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;
class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        bool neg = false;
        if ((numerator < 0 && denominator > 0) || (numerator > 0 && denominator < 0))
            neg = true;
        long n = abs((long)numerator / (long)denominator);
        long n1 = abs((long)numerator % (long)denominator);
        if (n1 == 0) {
            return neg? '-' + std::to_string(n): std::to_string(n);
        }

        long divide = abs((long)denominator);
        string ans = to_string(n) + ".";
        string tmp;
        unordered_map<long, int> mp;
        int i = 0;
        while (true) {
            if (mp.count(n1)){
                int idx = mp[n1];
                ans += tmp.substr(0, idx);
                ans += '(';
                ans += tmp.substr(idx);
                ans += ')';
                break;
            }
            mp.insert({n1, i});
            n1 *= 10;
            if (n1 < divide) {
                if (!mp.count(n1)) {
                    tmp += '0';
                }
            } else {
                tmp += '0' + n1 / divide;
                n1 = n1 % divide;
                if (n1 == 0) {
                    ans += tmp;
                    break;
                }
            }
            i++;
        }

        return neg? '-' + ans: ans;
    }
};
