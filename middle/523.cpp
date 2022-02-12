#include<vector>
#include<unordered_map>
#include<unordered_set>
#include<iostream>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int m = nums.size();
        if (m < 2) {
            return false;
        }
        unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < m; i++) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int prevIndex = mp[remainder];
                if (i - prevIndex >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }
        return false;
    }
};
int main(){
	vector<int> nums = {23,2,4,6,6};
	int k = 7;
	/* vector<int>nums = {23,2,4,6,7};
	 * int k = 6; */
	Solution s;
	bool ans = s.checkSubarraySum(nums, k);
	cout<< ans<< endl;
	return 0;
}
