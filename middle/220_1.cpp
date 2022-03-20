#include <vector>
#include <set>
#include <climits>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		int n = nums.size();
        set<int> rec;
        for (int i = 0; i < n; i++) {
            auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
            if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
                return true;
            }
            rec.insert(nums[i]);
            if (i >= k) {
                rec.erase(nums[i - k]);
            }
        }
        return false;

    }
};
int main() {
	map<int, int> mp;
	mp.insert({1, 4});
	mp.insert({4, 4});
	mp.insert({3, 4});
	auto iter = mp.lower_bound(2);
	cout<< iter->first<< "\t"<< iter->second<< endl;
	cout<< (--iter)->first<< "\t"<< (iter)->second<< endl;
	iter = mp.lower_bound(5);
	cout<< (iter == mp.end())<< endl;

	return 0;
}
