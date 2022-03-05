#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
		vector<int> table(nums.size());
		vector<int> stk;
		int ans = 0;
		stk.push_back(-1);

		for(int i = 0; i < nums.size(); i++){
			while(stk.size() > 1 && nums[i] > nums[stk.back()]){
				int back = stk.back();
				stk.pop_back();
				table[back] = (i - back) * (back - stk.back());
			}
			stk.push_back(i);
		}

		while(stk.size() > 1){
			int back = stk.back();
			stk.pop_back();
			table[back] = (nums.size() - back) * (back - stk.back());
		}
		for(int i = 0; i < table.size(); i++){
			if(nums[i] >= left && nums[i] <= right)
				ans += table[i];
		}

		return ans;
    }
};
int main(){
	vector<int>nums = {2,1,4,3};
	int left = 2; 
	int right = 3;
	Solution s;	
	cout<< s.numSubarrayBoundedMax(nums, left, right)<< endl;
	return 0;
}
