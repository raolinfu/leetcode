#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        int maxNum = INT_MIN;
        vector<int> left(n);
        vector<int> right(n);
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, height[i]);
            left[i] = maxNum;
        }

        maxNum = INT_MIN;
        for (int i = n - 1; i >= 0 ; i--) {
            maxNum = max(maxNum, height[i]);
            right[i] = maxNum;
        }

        for (int i = 0; i < n; i++) {
            if (left[i] > height[i] && right[i] > height[i])
                ans += min(left[i], right[i]) - height[i];
        }

        return ans;
    }
};
