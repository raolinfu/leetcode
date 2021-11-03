#include<vector>
#include<climits>
#include<iostream>

using namespace std;

int maxProfit(vector<int> &prices){
	int res = INT_MIN;
	if(prices.size() == 0)
		return 0;
	vector<int> dp(prices.size(), 0);
	vector<int> dp1(prices.size(), 0);
	int minNum = prices[0];
	int maxNum = prices[prices.size() - 1];
	for(int i = 1; i < prices.size(); i++){
		minNum = min(minNum, prices[i]);
		dp[i] = prices[i] - minNum > dp[i - 1]? prices[i] - minNum: dp[i - 1];
	}
	for(int i = prices.size() - 2; i >= 0; i--){
		maxNum = max(maxNum, prices[i]);
		dp1[i] = maxNum - prices[i] > dp1[i + 1]? maxNum - prices[i]: dp1[i + 1];
	}
	for(int i = 0; i < prices.size(); i++){
		res = max(res, dp[i] + dp1[i]);
	}

	return res;
}

int main(){
	vector<int> nums = {1, 6, 3, 43, 45, 23};
	// vector<int> nums = { 6, 5, 3};
	cout<< maxProfit(nums)<< endl;
	vector<int> prices = {1,2,3,4,5};
	cout<< maxProfit(prices)<< endl;
	vector<int> prices1 = {3,3,5,0,0,3,1,4};
	cout<< maxProfit(prices1)<< endl;
	return 0;
}
