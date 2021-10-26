#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<vector>
using namespace std;
void process(vector<int> &nums, vector<int> &res, vector<int>& tmp, unordered_set<int>visit, int pre, int idx){
	for(int i = idx; i < nums.size(); i++){
		if(visit.count(nums[i]))
			continue;
		if(nums[i] % pre == 0){
			tmp.push_back(nums[i]);	
			visit.insert(nums[i]);
			res = res.size() >= tmp.size()? res: tmp;
			process(nums, res, tmp, visit, nums[i], i + 1);
			tmp.pop_back();
		}
	}	
}
// 递归解法 会超时
vector<int> largestDivisibleSubset(vector<int>& nums) {
	vector<int> res;
	vector<int> tmp;
	unordered_set<int> visit;
	sort(nums.begin(), nums.end());
	for(int i = 0; i < nums.size(); i++){
		if(visit.count(nums[i]))
			continue;
		tmp.push_back(nums[i]);	
		process(nums, res, tmp, visit, nums[i], i + 1);
		tmp.pop_back();
	}

	return res;
}

// 动态规划
vector<int> largestDivisibleSubset1(vector<int>& nums) {
	vector<int> res;
	vector<int> dp(nums.size(), 1);
	sort(nums.begin(), nums.end());
	int maxLen = 0;
	int pre = 0;
	for(int i = 0; i < nums.size(); i++){
		for(int j = 0; j < i; j++){
			if(nums[i] % nums[j] == 0){
				dp[i] = max(dp[i], dp[j] + 1);
				if(maxLen < dp[i]){
					maxLen = dp[i];
					pre = nums[i];
				}
			}
		}
	}
	for(int i = nums.size() - 1; i >= 0; i--){
		if(dp[i] == maxLen && pre % nums[i] == 0){
			res.push_back(nums[i]);
			pre = nums[i];
			maxLen--;
		}
	}
	return res;
}
int main(){
	// vector<int> nums = {1,2,4,8};
	// vector<int> nums = {1,2,3};
	vector<int> nums = {5,9,18,54,108,540,90,180,360,720};
	// vector<int> nums = {1,2,5, 16, 25,32, 100};
	vector<int> res = largestDivisibleSubset1(nums);
	for(int i = 0; i < res.size(); i++)
		cout<< res[i]<< endl;

	return 0;
}
