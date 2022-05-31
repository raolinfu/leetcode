#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans = 0;
        int sum = 0;
        int l = 0;
        int r = 0;
        unordered_map<int, int> mp;

        while (r < nums.size()) {
            mp[nums[r]]++;
            sum += nums[r];
            while (mp[nums[r]] == 2) {
                mp[nums[l]]--;
                sum -= nums[l];
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);
                l++;
            }

            ans = max(sum ,ans);
            r++;
        }

        return ans;
    }
};
