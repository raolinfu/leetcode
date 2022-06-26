#include <string>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int dp[501][501];
        int n = s.length();
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = 0;
            if (i + 1 < s.length())
                dp[i][i + 1] = s[i] == s[i + 1]? 0: 1;
        }

        for (int i = s.length() - 1; i >= 0; i--) {
            for (int j = i + 2; j < s.length(); j++) {
                dp[i][j] = min(dp[i][j - 1], dp[i + 1][j]) + 1;
                if (s[i] == s[j])
                    dp[i][j] = min(dp[i][j], dp[i + 1][j - 1]);
            }
        }

        return dp[0][n - 1];
    }
};
