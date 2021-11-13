#include<vector>
#include<iostream>
#include<algorithm>
using namespace  std;

bool process(vector<int>& nums, int &tar, int cur, int idx);
bool canPartition(vector<int>& nums) {
	int sum = 0;
	int cur = 0;
	vector<int> dp(nums.size(), 0);
	sort(nums.begin(), nums.end());
	for(int n: nums)
		sum += n;
	if(sum % 2 != 0)
		return false;
	int tar = sum / 2;
	return process(nums, tar, cur, 0);

}
// 超时
bool process(vector<int>& nums, int &tar, int cur, int idx){
	if(cur == tar)
		return true;
	for(int i = idx; i < nums.size(); i++){
		if(cur + nums[i] > tar)
			return false;
		if(process(nums, tar, cur + nums[i], i + 1))
			return true;
		if(process(nums, tar, cur, i + 1))
			return true;
	}

	return false;
}

// 动态规划 01背包问题
bool canPartition1(vector<int>& nums) {
	int sum = 0;
	int len = nums.size();
	sort(nums.begin(), nums.end());
	for(int n: nums)
		sum += n;
	if(sum % 2 != 0)
		return false;
	sum = sum / 2;
	vector<vector<bool>> dp(len, vector<bool>(sum + 1, false));
	for(int i = 0; i < len; i++)
		dp[i][0] = true;
	for(int j = 0; j <= sum; j++){
		if(nums[0] == j)
			dp[0][j] = true;
	}
	for(int i = 1; i < len; i++){
		for(int j = 1; j <= sum; j++){
			// 没有nums[i]
			if(dp[i - 1][j]){
				dp[i][j] = true;
				continue;
			}
			// 有nums[i]
			if(j - nums[i] >= 0 && dp[i - 1][j - nums[i]]){
				dp[i][j] = true; 
			}
		}
	}

	/* for(int i = 0; i < len; i++){
	 *     cout<< nums[i]<< " ";
	 * } */
	/* cout<< endl<<  "--------"<< endl;
	 * for(int i = 0; i < len; i++){
	 *     for(int j = 0; j <= sum; j++){
	 *         cout<< dp[i][j]<<" ";
	 *     }
	 *     cout<< endl;
	 * } */
	
	
	return dp[len - 1][sum];
}
int main(){
	vector<int> nums = {1,5,11,5};
	// vector<int> nums = {6,12,3,4,5};
	// vector<int> nums = {1,2,5};
	// bool res = canPartition(nums);
	bool res = canPartition1(nums);
	cout<< res<< endl;
	return 0;
}
