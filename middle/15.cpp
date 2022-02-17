#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> ans;
		int n = nums.size();
		std::sort(nums.begin(), nums.end());
		int i = 0;
		while(i < n){
			// cout<< "i: "<< i<< endl;
			if(i > 0 && nums[i] == nums[i - 1]){
				i++;
				continue;
			}
			int j = i + 1;
			int k = n - 1;
			while(j < k){
				if(nums[j] + nums[k] + nums[i] == 0){
					ans.push_back(vector<int>{nums[i], nums[j], nums[k]});
					// cout<< "j: "<< j<< endl;
					while(j + 1 < n && nums[j] == nums[j + 1])
						j++;
					while(k - 1 > 0 && nums[k] == nums[k - 1])
						k--;
					// cout<< "k: "<< k<< endl;
					j++;
				}
				else if(nums[j] + nums[k] + nums[i] > 0){
					k--;
				}else{
					j++;
				}
			}
			i++;
		}

		return ans;
    }
};

int main(){
	Solution s;
	// vector<int>nums = {-1,0,1,2,-1,-4};
	vector<int>nums = {0};
    vector<vector<int>> ans = s.threeSum(nums);
	for(auto v: ans){
		for(auto ele: v){
			cout<< ele<< " ";
		}
		cout<< endl;
	}

	return 0;
}
