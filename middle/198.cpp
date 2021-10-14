#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

int rob(vector<int>& nums) {
	int len = nums.size();
	int res = 0;
	if(len == 0)
		return 0;

	int *dp = new int[len];
	dp[0] = nums[0];
	for(int i = 1; i < len; i++){
		if(i == 1)
			dp[i] = max(dp[0], nums[i]);
		dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); 
	}

	res = dp[len - 1];
	delete[] dp;
	return res;
}
int rob1(vector<int>& nums) {
	// f(n) = max(nums[n] + f(n - 2), f(n - 1))	
	int first = nums[0];
	if(nums.size() < 2)
		return first;
	int second  = max(nums[1], first);
	int res = max(first, second);
	for(int i = 2; i < nums.size(); i++){
		res = max(nums[i] + first, second);	
		first = second;
		second = res;
	}

	return res;
	
}

int main(){
	vector<int> nums = {1, 2, 3, 1};
	int res = rob(nums);
	return 0;
}
