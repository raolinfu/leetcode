#include<vector>
#include<climits>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
		vector<vector<int>> ans;
		vector<int> tmp;
		helper(ans, nums, tmp, INT_MIN, 0);

		return ans;
    }
	void helper(vector<vector<int>>& ans, vector<int>& nums, vector<int>& tmp, int last, int idx){
 		if(idx == nums.size()){
			if(tmp.size() > 1)
				ans.push_back(tmp);
			return;
		}
		if(nums[idx] >= last){
			tmp.push_back(nums[idx]);
			helper(ans, nums, tmp, nums[idx], idx + 1);
			tmp.pop_back();
		}

		if(nums[idx] != last){
			helper(ans, nums, tmp, last, idx + 1);
		}
	}
};
int main(){
	Solution s;
	// vector<int> nums = {4,6,7,7};
	vector<int> nums = {4,4,3,2,1};
	auto ans = s.findSubsequences(nums);
	for(auto v: ans){
		for(auto e: v){
			cout<< e<< "\t";
		}
		cout<< endl;
	}
	return 0;
}
