#include <vector>
#include <unordered_map>
#include <climits>
using namespace std;
/* 
 * dp[i][j] = max(dp[i][j - x], dp[i - 1][j - 1]) 1 <= x <= j 
 *
 * */
class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<long>> dp(k + 1, vector<long>(n + 1, INT_MAX));

        // 只剩0层楼
        for (int i = 0; i <= k; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= n; j++) {
                // 用二分法
                int l = 1;
                int r = j;
                while (l + 1 < r) {
                    int x = (l + r) >> 1;
                    int t1 = dp[i - 1][x - 1];
                    int t2 = dp[i][j - x];
                    if (t1 < t2) {
                        l = x;
                    } else if (t1 > t2) {
                        r = x;
                    } else {
                        l = r = x;
                    }
                }

                dp[i][j] = 1 + min(max(dp[i - 1][ l - 1], dp[i][ j - l]),
                                   max(dp[i - 1][ r - 1], dp[i][ j - r]));

                /* for (int x = 1; x <= j; x++) {
                 *     dp[i][j] = min(dp[i][j], 1 + max(dp[i][j - x], dp[i - 1][x - 1]));
                 * } */
            }
        }


        return dp[k][n];
    }
};

class Solution1 {
    unordered_map<int, int> memo;

    int dp(int k, int n) {
        if (memo.find(n * 100 + k) == memo.end()) {
            int ans;
            if (n == 0) {
                ans = 0;
            } else if (k == 1) {
                ans = n;
            } else {
                int lo = 1, hi = n;
                while (lo + 1 < hi) {
                    int x = (lo + hi) / 2;
                    int t1 = dp(k - 1, x - 1);
                    int t2 = dp(k, n - x);

                    if (t1 < t2) {
                        lo = x;
                    } else if (t1 > t2) {
                        hi = x;
                    } else {
                        lo = hi = x;
                    }
                }

                ans = 1 + min(max(dp(k - 1, lo - 1), dp(k, n - lo)),
                                   max(dp(k - 1, hi - 1), dp(k, n - hi)));
            }

            memo[n * 100 + k] = ans;
        }

        return memo[n * 100 + k];
    }
public:
    int superEggDrop(int k, int n) {
        return dp(k, n);
    }
};

