#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        long sum = 0; 
        int max_num = INT_MIN;
        for (auto n: candies) {
            max_num = max(max_num, n);
            sum += n;
        }
        if (sum < k)
            return 0;
        int l = 1;
        int r = max_num;
        while (l <= r) {
            int m = (r - l) / 2 + l;
            if (isValid(candies, k, m)) {
                l = m + 1;
            } else {
                r = m - 1;
            }
        }

        return l - 1;
    }

    bool isValid(vector<int>& candies, long long& k, int tar) {
        long long cnt = 0;
        for (auto n :candies) {
            cnt += n / tar;
            if (cnt >= k)
                return true;
        }
        return false;
    }
};
