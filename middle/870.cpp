#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
		int n = nums1.size();
		vector<int> ans(n);
		priority_queue<pair<int, int>> q;
		sort(nums1.begin(), nums1.end());
		for (int i = 0; i < n; i++)
			q.push({nums2[i], i});
		int l = 0;
		int r = n - 1;
		while (!q.empty()) {
			auto [k, v] = q.top();
			if(k >= nums1[r]) {
				ans[v] = nums1[l++];
			} else {
				ans[v] = nums1[r--];
			}

			q.pop();
		}

		return ans;
    }
};
