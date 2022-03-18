#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
		unordered_map<int, int> mp;
		int ans = 0;
		for (auto n: time) {
			int mode = n % 60;
			if (mode == 0) {
				ans += mp[0];
				mp[0]++;
			} else {
				ans += mp[60 - mode];
				mp[mode]++;
			}
		}

		return ans;
    }
};
