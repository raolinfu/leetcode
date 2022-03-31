#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> numMovesStones(int a, int b, int c) {
		vector<int> tmp{a, b, c};
		vector<int> ans(2);
		sort(tmp.begin(), tmp.end());
		int i1 = tmp[1] - tmp[0];
		int i2 = tmp[2] - tmp[1];
		if (i1 == 1 && i2 == 1)
			ans[0] = 0;
		else if (i1 == 1 || i2 == 1 || i1 == 2 || i2 == 2)
			ans[0] = 1;
		else
			ans[0] = 2;
		ans[1] = i1 + i2 - 2;
		return ans;
    }
};
