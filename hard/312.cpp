#include <vector>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> eles(n + 2);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        eles[0] = 1;
        eles[n + 1] = 1;

        for (int i = 1; i <= n; i++) {
            eles[i] = nums[i - 1];
        }

        for (int i = n + 1; i >= 0; i--) {
            for (int j = i + 2; j < n + 2; j++) {
                for (int k = i + 1; k < j; k++) {
                    int sum = dp[i][k] + dp[k][j] + eles[k] * eles[i] * eles[j];
                    dp[i][j] = max(dp[i][j], sum);
                }
            }
        }

        return dp[0][n + 1];
    }
};
