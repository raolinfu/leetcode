#include <string>
using namespace std;

class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int x_num = 0;
        int y_num = 0;
        int n1 = 0;
        int n2 = 0;
        int n = s1.length();
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s1[i] == 'x') {
                x_num++;
            } else {
                y_num++;
            }

            if (s2[i] == 'x') {
                x_num++;
            } else {
                y_num++;
            }

            if (s1[i] == s2[i]) {
                continue;
            } else if (s1[i] == 'x'){
                n1++;
            } else {
                n2++;
            }
        }

        if (x_num % 2 || y_num % 2)
            return -1;
        if (n1 % 2) {
            cnt += n1 / 2 + n2 / 2 + 2;
        } else {
            cnt += n1 / 2 + n2 / 2;
        }

        return cnt;
    }
};
