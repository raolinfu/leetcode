#include <vector>
#include <iostream>
#include <map>
#include <climits>

using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        int l = 0;
        int r = -1;
        int n = nums.size();
        map<int, int> mp;
        while (r < n) {
            if (r - l == k - 1) {
                ans.push_back(mp.rbegin()->first);
                if (r == n - 1)
                    break;
            }
            r++;
            mp[nums[r]]++;
            if (r - l == k) {
                if (mp[nums[l]] == 1) {
                    mp.erase(nums[l]);
                }
                else
                    mp[nums[l]]--;
                l++;
            }
        }

        return ans;
    }
};
int main() {

    /* vector<int> nums = {1,3,-1,-3,5,3,6,7};
     * int k = 3; */
    vector<int> nums = {5,4,3};
    int k = 1;
    Solution sol;
    auto ans = sol.maxSlidingWindow(nums, k);
    for (auto n: ans)
        cout<< n<< "\t";
    cout<< endl;
    map<int, int> mp{{1, 2}, {3, 4}};
    mp.erase(1);
    // mp.erase(3);
    for (auto it: mp)
        cout<< it.first<< "\t"<< it.second;

    return 0;
}
