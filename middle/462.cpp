#include<vector>
#include<iostream>
using namespace std;

int minMoves2(vector<int>& nums) {
	int res = 0;
	long sum = 0;
	int len = nums.size();
	vector<long> dp(len);
	for(int i = 0; i < len; i++){
		sum += nums[i];
		dp[i] = sum;
	}
	for(int i = 0; i < len; i++){
		// res = min<int>(res, (i + 1) * nums[i] - dp[i] + sum -dp[i] - (len - i - 1) * nums[i]);
		res = min<int>(res, (2 * i + 2 - len) * nums[i] - 2 * dp[i] + sum);
	}

	return res;
}
