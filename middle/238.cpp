#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();
		vector<int> left2right(n);
		vector<int> right2left(n);
		vector<int> ans(n);
		int m = nums[0];
		left2right[0] = m;
		for (int i = 1; i < n; i++) {
			m *= nums[i];
			left2right[i] = m;
		}
		m = nums[n - 1];
		right2left[n - 1] = m;
		for (int i = n -2; i >=0; i--) {
			m *= nums[i];
			right2left[i] = m;
		}
		for (int i = 0; i < n; i++) {
			if (i == 0) {
				ans[i] = right2left[i + 1];
			} else if (i == n - 1) {
				ans[i] = left2right[i - 1];
			} else {
				ans[i] = left2right[i - 1] * right2left[i + 1];
			}
		}


		return ans;
    }
};
