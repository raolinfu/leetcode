#include<vector>
#include<iostream>
using namespace std;

void process(vector<int>& nums, int &target, int &res, int sum, int idx);
int findTargetSumWays(vector<int>& nums, int target) {
	int res = 0;
	process(nums, target, res, 0, 0);

	return res;
}

void process(vector<int>& nums, int &target, int &res, int sum, int idx){
	if(idx == nums.size()){
		res = sum == target? res + 1: res;
		return;
	}

	process(nums, target, res, sum + nums[idx], idx + 1);
	process(nums, target, res, sum - nums[idx], idx + 1);
}

int main(){
	vector<int>nums = {1,1,1,1,1};
	int target = 3;
	int res = findTargetSumWays(nums, target);
	cout<< res<< endl;
	return 0;
}
