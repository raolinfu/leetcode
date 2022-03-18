#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int knightDialer(int n) {
		int ans = 0;
		int mod = pow(10, 9) + 7;
		vector<vector<int>> dp(n, vector<int>(10));
		for (int i = 0; i < 10; i++)
			dp[0][i] = 1;
		for (int i = 1; i < n; i++) {
			dp[i][0] = (dp[i - 1][4] + dp[i - 1][6]) % mod;
			dp[i][1] = (dp[i - 1][8] + dp[i - 1][6]) % mod;
			dp[i][2] = (dp[i - 1][7] + dp[i - 1][9]) % mod;
			dp[i][3] = (dp[i - 1][4] + dp[i - 1][8]) % mod;
			dp[i][4] = (dp[i - 1][3] + dp[i - 1][9] + dp[i - 1][0]) % mod;
			dp[i][6] = (dp[i - 1][7] + dp[i - 1][1] + dp[i - 1][0]) % mod;
			dp[i][7] = (dp[i - 1][2] + dp[i - 1][6]) % mod;
			dp[i][8] = (dp[i - 1][1] + dp[i - 1][3]) % mod;
			dp[i][9] = (dp[i - 1][2] + dp[i - 1][4]) % mod;
		}
		for (int i = 0; i < 10; i++) {
			ans = (ans + dp[n - 1][i]) % mod;
		}

		return ans;
    }
};
