#include <vector>
#include <iostream>
#include <climits>
using namespace std;

/* 
 * 这里股票可以买很多次 只是只能在手里无股票是才能买入
 * dp[i][0] 表示没有在i这天买入 dp[i][1]表示有买入
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
        int dp[n][2];
		// 允许负收益
        dp[0][0] = 0, dp[0][1] = -prices[0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }
        return dp[n - 1][0];
    }
};
