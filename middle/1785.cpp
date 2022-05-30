#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long sum = 0;
        long ans;
        for (auto n: nums)
            sum += n;
        long diff = goal - sum;
        diff = abs(diff);
        if (diff == 0)
            return 0;

        ans = diff / limit;
        if (diff % limit)
            ans += 1;

        return ans;
    }
};
