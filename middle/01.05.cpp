#include <string>
using namespace std;

class Solution {
public:
    bool oneEditAway(string first, string second) {
        int len1 = first.length();
        int len2 = second.length();
        if (len1 == len2) {
            int diff = 0;
            for (int i = 0; i < len1; i++) {
                if (first[i] != second[i])
                    diff++;
            }

            return diff == 0 || diff == 1;
        } else if(len1 + 1 == len2 || len1 == len2 + 1) {
            string& str1 = len1 + 1 == len2? first: second;
            string& str2 = len1 + 1 == len2? second: first;
            int i = 0;
            int j = 0;
            bool flag = false;
            while (i < str1.length()) {
                if (!flag && str1[i] != str2[j]) {
                    flag = true;
                    j++;
                    continue;
                } else if (flag && str1[i] != str2[j]) {
                    return false;
                }

                i++;
                j++;
            }
            return true;
        } else {
            return false;
        }
    }
};