#include <vector>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
		int length = arr.size();
        vector<int> dp(length);
        for (int i = 1; i <= k; i++) {
            dp[i - 1] = getMaxValue(arr, 0, i - 1) * i;
        }
        for (int i = k; i < length; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i] = max(dp[i - j] + getMaxValue(arr, i - j + 1, i) * j, dp[i]);
            }
        }

        return dp[length - 1];
    }

	int getMaxValue(vector<int>& arr, int start, int end) {
        int res = 0;
        for (int i = start; i <= end; i++) {
            res = max(res, arr[i]);
        }
        return res;
    }
};
