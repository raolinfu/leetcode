#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
		int n = nums.size();
		vector<int> ans(n, -1);
		stack<int> stk;
		stk.push(0);
		for(int i = 0; i < n * 2 - 1; i++){
			int k = i % n;
			while(!stk.empty() && nums[k] > nums[stk.top()]){
				nums[stk.top()] = nums[k];
				stk.pop();
			}
			stk.push(k);
		}

		return ans;
    }
};
