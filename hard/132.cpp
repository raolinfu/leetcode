#include <string>
#include <climits>
#include <vector>
using namespace std;
/* 
 * dp[i][j] = dp[i + 1][j - 1] s[i] == s[j] 且j > i
 * res[i][j] = res[i - k] + res[k + 1][j]
 * */
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, true));
        vector<int> res(n, INT_MAX);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (dp[0][i])
                res[i] = 0;
            else {
                for (int j = 0; j < i; ++j) {
                    if (dp[j + 1][i]) {
                        res[i] = min(res[i], res[j] + 1);
                    }
                }
            }
        }

        return res[n - 1];
    }
};
