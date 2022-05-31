#include <vector>
using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int first;
        int second;
        int cnt = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                first = i - 1;
                second = i;
                cnt++;
            }
        }

        if (cnt == 0) {
            return true;
        } else if (cnt >= 2) {
            return false;
        }

        if (second == nums.size() - 1 || first == 0)
            return true;
        if (nums[first - 1] <= nums[second] || nums[first] <= nums[second + 1])
            return true;

        return false;
    }
};
