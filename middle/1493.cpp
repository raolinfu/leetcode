#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int cnt = 0;
        int res = 0;
        while (r < n)
        {
            if (nums[r] == 0) {
                if (cnt == 0) {
                    res = max(res, r - l);
                    ++cnt;
                    ++r;
                } else {
                    while (l < n && nums[l] != 0) {
                        ++l;
                    }
                    ++l;
                    res = max(res, r - l);
                    ++r;
                }
            } else {
                res = max(res, r - l);
                ++r;
            }
        }
        
        return res;
    }
};