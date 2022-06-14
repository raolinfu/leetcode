#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int mergeStones(vector<int>& stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1) != 0)
			return -1;

		vector<vector<int>> dp(n + 1, vector<int>(n + 1));
		vector<int> sum(n + 1);
        for (int i = 1; i <= n; ++i) 
			sum[i] = sum[i - 1] + stones[i - 1];

        for (int len = k; len <= n; ++len) { // 枚举区间长度
            for (int i = 1; i + len - 1 <= n; ++i) { // 枚举区间起点
                int j = i + len - 1;
                dp[i][j] = INT_MAX;
                for (int p = i; p < j; p += k - 1) {  // 枚举分界点
                    dp[i][j] = min(dp[i][j], dp[i][p] + dp[p + 1][j]);
                }

                if ((j - i) % (k - 1) == 0)
					dp[i][j] += sum[j] - sum[i - 1];
            }
        }

        return dp[1][n];
    }
};


