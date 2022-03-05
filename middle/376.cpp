#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
		int ans = 1;
		vector<int> dp1(nums.size(), 1);
		vector<int> dp2(nums.size(), 1);
		for(int i = 1; i < nums.size(); i++){
			for(int j = 0; j < i; j++){
				if(nums[i] > nums[j])
					dp1[i] = max(dp1[i], dp2[j] + 1);
				if(nums[i] < nums[j])
					dp2[i] = max(dp2[i], dp1[j] + 1);
			}
			ans = max(ans, max(dp1[i], dp2[i]));
		}

		return ans;
    }
};
