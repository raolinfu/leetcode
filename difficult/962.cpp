#include<vector>
#include<iostream>
using namespace std;
/* 
 * 超时
 * */
int maxWidthRamp(vector<int>& nums) {
	int res = 0;
	vector<int> dp(nums.size(), 0);
	dp[0] = 0;
	for(int i = 1; i < nums.size(); i++){
		for(int j = 0; j < i; j++){
			if(nums[i] >= nums[j]){
				dp[i] = max(dp[i], dp[j] + i - j);
			}
		}
		res = max(res, dp[i]);
	}

	return res;
}
int maxWidthRamp1(vector<int>& nums) {
	int res = 0;
	vector<int> dp(nums.size(), 0);
	dp[0] = 0;
	for(int i = 1; i < nums.size(); i++){
		for(int j = 0; j < i; j++){
			if(nums[i] >= nums[j]){
				dp[i] = max(dp[i], dp[j] + i - j);
			}
		}
		res = max(res, dp[i]);
	}

	return res;
}
