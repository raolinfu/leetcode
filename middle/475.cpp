#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		int len = heaters.size();
		int ans = 0;
		sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
		for (auto tar: houses) {
			int low = getLower(heaters, tar);
			int up = getUp(heaters, tar);
			int tmp;
			if (low == -1) {
				tmp = heaters[up] - tar;
			} else if (up == len) {
				tmp = tar - heaters[low];
			} else {
				tmp = min(heaters[up] - tar, tar - heaters[low]);
			}
			ans = max(ans, tmp);
		}

		return ans;
    }
	int getUp(vector<int>& nums, int tar) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (nums[m] >= tar) {
				r = m - 1;
			} else {
				l = m + 1;
			}
		}

		return l;
	}
	int getLower(vector<int>& nums, int tar) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (nums[m] < tar) {
				l = m + 1;
			} else {
				r = m - 1;
			}
		}
		
		return r;
	}
};
