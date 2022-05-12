#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    string orderlyQueue(string s, int k) {
        string res = s;
        if (k == 1) {
            for (int i = 0; i < s.length(); i++) {
                string tmp = s.substr(i) + s.substr(0, i);
                res = min(res, tmp);
            }

            return res;
        } else {
            sort(s.begin(), s.end());
            return s;
        } 
    }
};
