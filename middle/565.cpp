#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
		int n = nums.size();
		int ans = 1;
		vector<bool> visited(n, false);
		for (int i = 0; i < n; i++) {
			if (visited[nums[i]] == false) {
				int res = backtrace(nums, visited, nums[i], 0);
				ans = max(ans, res);
			}
		}

		return ans;
    }

	int backtrace(vector<int>& nums,vector<bool>& visited, int n, int cnt) {
		if (mp.count(n))
			return mp[n];
		if (visited[n])
			return cnt;
		visited[n] = true;
		mp[n] = backtrace(nums, visited, nums[n], cnt + 1);
		return mp[n];
	}
private:
	unordered_map<int, int> mp;
};
