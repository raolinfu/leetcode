#include <vector>
#include <climits>
#include <queue>

using namespace std;
using pii = pair<int, int>;

struct Cmp {
    bool operator()(const pii &a, const pii &b) {
        return a.first > b.first;
    }
};

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<int> pointers(n, 0);
        std::priority_queue<pii, vector<pii>, Cmp> priq;
        int maxNum = INT_MIN;
        int len = INT_MAX;
        int l;
        int r;

        for (int i = 0; i < n; i++) {
            int first = nums[i][pointers[i]];
            int second = i;
            maxNum = max(maxNum, first);
            ++pointers[i];
            priq.push({first, second});
        }

        while (priq.size() == n) {
            auto [first, second] = priq.top();
            priq.pop();

            if (len > maxNum - first) {
                len = maxNum - first;
                l = first;
                r = maxNum;
            }

            if (pointers[second] >= nums[second].size())
                break;

            first = nums[second][pointers[second]];
            maxNum = max(maxNum, first);
            priq.push({first, second});
            ++pointers[second];
        }

        return {l, r};
    }
};
