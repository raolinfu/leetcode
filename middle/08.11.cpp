#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int waysToChange(int n) {
        int mode = pow(10, 9) + 7;
        int res = 0;
        vector<int> values{1, 5, 10, 25};
        vector<vector<int>> dp(n + 1, vector<int>(5));
        for (int j = 0; j < 4; j++)
            dp[0][j] = 1;

        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < 4; j++) {
                dp[i][j] = dp[i][j - 1];
                if (i > values[j]) {
                    dp[i][j] += dp[i - values[j]][j];
                }
                dp[i][j] %= mode;
            }
        }

        return dp[n][3];
    }
};