#include <vector>
#include <unordered_map>
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		unordered_map<int, int> mp;
		vector<int> ans;
		for (auto n: nums) {
			mp[n]++;	
		}
		for (auto [k, v]: mp) {
			if (v == 1)
				ans.push_back(k);
		}
		
		return ans;
    }
};
