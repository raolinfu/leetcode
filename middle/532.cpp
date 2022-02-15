#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
		unordered_set<int> set;
		unordered_set<int> res;
		sort(nums.begin(), nums.end());
		for(int i = 0; i < nums.size(); i++){
			if(set.count(nums[i] - k)){
				res.insert(nums[i] - k);
			}
			set.insert(nums[i]);
		}

		return res.size();
    }

    int findPairs1(vector<int>& nums, int k) {
		unordered_set<int> set;
		unordered_set<int> res;
		for(int i = 0; i < nums.size(); i++){
			if(set.count(nums[i] - k)){
				res.insert(nums[i] - k);
			}

			if(set.count(nums[i] + k)){
				res.insert(nums[i]);
			}
			set.insert(nums[i]);
		}

		return res.size();
    }
};
int main(){
	Solution s;
	vector<int>nums = {3, 1, 4, 1, 5};
	int k = 2;
	int ans = s.findPairs1(nums, k);
	cout<< ans<< endl;
	return 0;
}
