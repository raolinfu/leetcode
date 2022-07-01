#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n);
        vector<int> right(n);
        int cur = 0;
        int maxNum = INT_MIN;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            if (cur < 0) {
                left[i] = arr[i];
                cur = arr[i];
            } else {
                cur += arr[i];
                left[i] = cur;
            }
            maxNum = max(maxNum, left[i]);
        }

        cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (cur < 0) {
                right[i] = arr[i];
                cur = arr[i];
            } else {
                cur += arr[i];
                right[i] = cur;
            }
            maxNum = max(maxNum, right[i]);
        }

        for (int i = 1; i < n - 1; i++) {
            ans = max(ans, left[i - 1] + right[i + 1]);
        }

        return ans > maxNum? ans: maxNum;
    }
};
