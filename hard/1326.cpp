#include <vector>
#include <numeric>
#include <climits>
using namespace std;

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int> prev(n + 1);
        iota(prev.begin(), prev.end(), 0);

        for (int i = 0; i <= n; ++i) {
            int l = max(i - ranges[i], 0);
            int r = min(i + ranges[i], n);
            prev[r] = min(prev[r], l);
        }

        int breakpoint = n, furthest = INT_MAX;
        int ans = 0;
        for (int i = n; i > 0; --i) {
            furthest = min(furthest, prev[i]);
            if (i == breakpoint) {
                if (furthest >= i) {
                    return -1;
                }
                breakpoint = furthest;
                ++ans;
            }
        }

        return ans;
    }
};


