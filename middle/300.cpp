#include<vector>
#include<iostream>
using namespace std;
/*
 *最长递增子序列
 *
 * 动态规划 以nums[i]结尾的最长递增子序列
 *
 *
 * */
int lengthOfLIS(vector<int>& nums) {
	int res = 0;
	vector<int> dp(nums.size(), 1);
	for(int i = 0; i < nums.size(); i++){
		for(int j = 0; j < i; j++){
			if(nums[i] > nums[j]){
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		res = max(res, dp[i]);
	}

	return res;
}

int main(){
	vector<int> nums = {4,10,4,3,8,9};
	// vector<int>	nums = {10,9,2,5,3,7,101,18};
	// vector<int> nums = {7,7,7,7,7,7,7};
	int res = lengthOfLIS(nums);
	cout<< res<< endl;

	return 0;
}
