#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
    int getMiddle(vector<vector<int>>& nums, int i) {
        cout<< "i:"<< i<< endl;
        int l = 0;
        int r = i - 1;
        while (l <= r) {
            int m = (l + r) >> 1;
            if (nums[m][1] <= nums[i][0]) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        if (r == -1)
            return -1;
        return l - 1;
    }

public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>  nums;
        vector<int> dp(n);
        for (int i = 0; i < n; i++) {
            nums.push_back({startTime[i], endTime[i], profit[i]});
        }

        sort(nums.begin(), nums.end(), [](const auto& v1, const auto& v2) {
                if (v1[1] < v2[1]) return true;
                else if (v1[1] == v2[1]) return v1[0] < v2[0];
                return false;
                });

        for (int i = 0; i < n; i++) {
            dp[i] = nums[i][2];
        }

        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i], dp[i - 1]);

            int mid = getMiddle(nums, i);
            if (mid >= 0)
                dp[i] = max(dp[i], dp[mid] + nums[i][2]);

            /*for (int j = i - 1; j >= 0; j--) {
                if (nums[j][1] <= nums[i][0]) {
                    dp[i] = max(dp[i], dp[j] + nums[i][2]);
                    break;
                }
            }*/
        }

        return dp[n - 1];
    }

};
