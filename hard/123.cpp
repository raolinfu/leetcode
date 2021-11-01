#include<vector>
#include<climits>
#include<iostream>

using namespace std;

void process(vector<int> &nums){
	int res = INT_MIN;
	if(nums.size() == 0)
		return;
	vector<int> dp(nums.size(), 0);
	vector<int> dp1(nums.size(), 0);
	int minNum = nums[0];
	int maxNum = nums[nums.size() - 1];
	for(int i = 1; i < nums.size(); i++){
		minNum = min(minNum, nums[i]);
		dp[i] = nums[i] - minNum > dp[i - 1]? nums[i] - minNum: dp[i - 1];
	}
	for(int i = nums.size() - 2; i >= 0; i--){
		maxNum = max(maxNum, nums[i]);
		dp1[i] = maxNum - nums[i] > dp1[i + 1]? maxNum - nums[i]: dp1[i + 1];
	}
	for(int i = 0; i < nums.size(); i++){
		cout<< dp[i]<< "\t";
	}
	cout << endl;
	for(int i = 0; i < nums.size(); i++){
		cout<< dp1[i]<< "\t";
	}
	cout << endl;
	for(int i = 0; i < nums.size(); i++){
		res = max(res, dp[i] + dp1[i]);
	}
	cout<< res<< endl;

}

int main(){
	vector<int> nums = {1, 6, 3, 43, 45, 23};
	// vector<int> nums = { 6, 5, 3};
	process(nums);
	vector<int> prices = {1,2,3,4,5};
	process(prices);
	vector<int> prices1 = {3,3,5,0,0,3,1,4};
	process(prices1);
	return 0;
}
