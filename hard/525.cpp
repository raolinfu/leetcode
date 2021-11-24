#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
	int res = 0;
	int sum = 0;
	vector<int> dp(nums.size());
	unordered_map<int, int> mp;
	mp.insert({0, -1});

	for(int i = 0; i < nums.size(); i++){
		nums[i] = nums[i]? nums[i]: -1;
	}
	for(int i = 0; i < nums.size(); i++){
		sum += nums[i];
		dp[i] = sum;
		if(!mp.count(sum))
			mp.insert({sum, i});
	}
	for(int i = 0; i < nums.size(); i++){
		res = max(res, i - mp[dp[i]]);	
	}

	return res;
}

int main(){
	// vector<int>nums = {0,1,0};
	vector<int>nums = {0,1,0, 1, 0};
	int res = findMaxLength(nums);
	cout<< res<< endl;

	return 0;
}
