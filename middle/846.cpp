#include<vector>
#include<algorithm>
#include<list>
#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
		map<int, int> mp;
		for(auto n: hand)
			mp[n]++;
		vector<pair<int, int>> nums(mp.begin(), mp.end());
		if(nums.size() < groupSize)
			return false;
		int left = 0;
		int right = groupSize - 1;
		while(left < right && right < nums.size()){
			int diff = nums[left].second;
			nums[left].second = 0;
			for(int i = left + 1; i <= right; i++){
				if(nums[i].first != nums[i - 1].first + 1 ||  nums[i].second - diff < 0)
					return false;
				nums[i].second -= diff;
			}
			while(left < nums.size() && nums[left].second == 0)
				left++;
			while(right - left != groupSize - 1 && right < nums.size())
				right++;
			if(right == nums.size() && left != nums.size())
				return false;
		}

		return true;
    }
};
int main(){
	Solution sol;
	vector<int> hand = {1,2,3,6,2,3,4,7,8};
	// vector<int> hand = {1,5};
	// vector<int> hand = {1,1,2, 2, 3, 3};
	int groupSize = 2;
	bool ans = sol.isNStraightHand(hand, groupSize);
	cout<< ans<< endl;
	return 0;
}
