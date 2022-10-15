#include <vector>
using namespace std;

class Solution {
	vector<vector<int>> res;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
		vector<int> tmp;
		dfs(nums, tmp, 0, nums.size());
		return res;
    }

	void dfs(vector<int>& nums, vector<int>& tmp, int idx, int n) {
		res.emplace_back(tmp);
		for (int i = idx; i < n; i++) {
			tmp.push_back(nums[i]);
			dfs(nums, tmp, i + 1, n);
			tmp.pop_back();
		}
	}
};
