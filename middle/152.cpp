#include<vector>
#include<iostream>
#include<climits>
using namespace std;
class Solution {
public:
    int maxProduct(vector<int>& nums) {
		int great = nums[0];
		int less = nums[0];
		int ans = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			if (great == 0) {
				great = nums[i];
				less = nums[i];
				ans = max(ans, great);
			} else {
                int a = max(great * nums[i], less * nums[i]);
                int b = min(great * nums[i], less * nums[i]);
				great = max(a, nums[i]);
				less = min(b, nums[i]);
			}
		}

		return ans;
    }
};
