#include<vector>
#include<climits>
#include<iostream>
using namespace std;

void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp, int idx, int last);
vector<vector<int>> getSubarray(vector<int>& nums){
	vector<vector<int>> ans;
	vector<int> tmp;
	helper(ans, nums, tmp, 0, INT_MIN);
	return ans;
}

void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp, int idx, int last){
	if(idx == nums.size()){
		ans.push_back(tmp);
		return;
	}
	if(nums[idx] >= last){
		tmp.push_back(nums[idx]);
		helper(ans, nums, tmp, idx + 1, nums[idx]);
		tmp.pop_back();
	}
	if(nums[idx] != last){
		helper(ans, nums, tmp, idx + 1, last);
	}
}

int main(){
	vector<int> nums = {1, 2, 5, 5, 7, 9};
	auto ans = getSubarray(nums);
	for(auto v: ans){
		for(auto ele: v){
			cout<< ele<< "\t";
		}
		cout<< endl;
	}
	return 0;
}
