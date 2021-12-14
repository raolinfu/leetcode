#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int combinationSum4(vector<int>& nums, int target) {
	int len = nums.size();
	vector<vector<int>> dp(len, vector<int>(target + 1, 0));
	for(int i = 0; i < len; i++)
		dp[i][0] = 1;
	for(int j = 0; j <= target; j++)
		dp[0][j] = target % nums[0] == 0? 1: 0;
	for(int i = 1; i < len; i++){
		for(int j = 1; j <= target; j++){
			dp[i][j] = dp[i - 1][j];
			if(j - nums[i] >= 0)
				dp[i][j] += dp[i][j - nums[i]];
			// 无nums[i]的情况 k = 0
			// 有nums[i]的情况 k > 0
			/* for(int k = 0; j - k * nums[i] >=0; k++){
			 *     dp[i][j] += dp[i - 1][j - k * nums[i]];
			 * } */
		}
	}
	for(int i = 0; i < len; i++){
		for(int j = 0; j <= target; j++){
			cout<< dp[i][j]<< " ";
		}
		cout<< endl;
	}

	return dp[len - 1][target];
}

int main(){
	vector<int> nums = {1,2,3};
	int target = 4;
	int res = combinationSum4(nums, target);
	cout<< res<< endl;
	return 0;
}
