#include <vector>
using namespace std;
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
		int tmp = 0;
		int res = 0;
		int s = 0;
		int l = 0;
		int r = 0;
		for (int i = 0; i < customers.size(); i++) {
			if (grumpy[i] == 0)
				s += customers[i];
		}
		while (l <= r && r < customers.size()) {
			// 在这里都要加上
			if (grumpy[r] == 1) {
				tmp += customers[r];
			}
			// 这里判断窗口是否合法
			if (r - l < minutes) {
				res = max(res, tmp);
			}
			if (r - l >= minutes) {
				if (grumpy[l] == 1) {
					tmp -= customers[l];
				}
				// 再判断一次
                res = max(res, tmp);
				l++;
			}
			r++;

		}

		return res + s;
    }
};
