#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
		sort(nums.begin(), nums.end());
		int i = 0;
		int diff = INT_MAX;
		int ans;
		while(i < nums.size()){
			int l = i + 1;
			int r = nums.size() - 1;
			while(l < r){
				int sum = nums[i] + nums[l] + nums[r];
				int d = sum - target;
				if(sum == target)
					return target;
				else if(sum < target){
					if(-d < diff){
						diff = -d;
						ans = sum;
					}
					l++;
				}
				else if(sum > target){
					if(d < diff){
						diff = d;
						ans = sum;
					}
					r--;
				}
			}

			i++;
		}

		return ans;
    }
};
