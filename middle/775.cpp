#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	// 超时
    bool isIdealPermutation(vector<int>& nums) {
 		int n = nums.size();
        int low = n;
        for (int i = n - 1; i >= 2; --i)
        {
            low = min(low, nums[i]);
            if (nums[i-2] > low)
            {
                return false;
            }
        }
        return true;

/*         stack<int> stk;
 *         int i = 0;
 *         stk.push(-1);
 *         while (i < nums.size()) {
 *             while (stk.size() > 1 && nums[stk.top()] > nums[i]) {
 *                 int top = stk.top();
 *                 stk.pop();
 *                 if (top - stk.top() > 2)
 *                     return false;
 *             }
 *             stk.push(i);
 *             i++;
 *         }
 *         while (stk.size() > 1) {
 *             int top = stk.top();
 *             stk.pop();
 *             if (top - stk.top() > 2)
 *                 return false;
 *         }
 *
 *         return true; */
    }
    bool isIdealPermutation1(vector<int>& nums) {
		for (int i = 0; i < nums.size(); i++) {
			for ( int j = 0; j < i; j++) {
				if (nums[j] > nums[i] && j - i > 1)
					return false;
			}
		}

		return true;
    }
};
