#include<vector>
#include<climits>
#include<algorithm>
#include<iostream>
using namespace std;

int minMoves2(vector<int>& nums) {
	sort(nums.begin(), nums.end());
	long res = LONG_MAX;
	long sum = 0;
	int len = nums.size();
	vector<long> dp(len);
	vector<long> right(len);
	for(int i = 0; i < len; i++){
		sum += nums[i];
		dp[i] = sum;
	}

	sum = 0;
	for(int i = len - 1; i >= 0; i--){
		sum += nums[i];
		right[i] = sum;
	}
	for(int i = 0; i < len; i++){
		long d1 = (long)(nums[i]) * (i + 1) - dp[i];
		long d2 = right[i] - (long)nums[i] * (len - i);
		long d = d1 + d2;
		res = min(res, d);
	}

	return res;
}
