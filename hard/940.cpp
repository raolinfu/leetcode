#include <string>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int distinctSubseqII(string s) {
        long ans = 0;
        int n = s.length();
        long mode = pow(10, 9) + 7;
        vector<long> dp(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (s[i] != s[j]) {
                    dp[i] += dp[j] % mode;
                }
            }
        }

        for (int i = 0; i < n; i++) {
            ans = (ans % mode + dp[i] % mode) % mode;
        }

        return ans;
    }
};
