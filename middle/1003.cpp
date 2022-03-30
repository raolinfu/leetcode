#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        string cur;
        if (len % 3)
            return false;

        for (auto ch: s) {
            cur += ch;
            while (cur.back() == 'c' && 
                    cur.length() >= 3 && 
                    cur.substr(cur.length() - 3) == "abc") {
                cur.pop_back();
                cur.pop_back();
                cur.pop_back();
            }
        }

        return cur.length() == 0;
    }
};
