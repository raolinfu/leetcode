#include <vector>
#include <cmath>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        int len1 = a.size();
        int len2 = b.size();
        int res = INT_MAX;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int i = 0;
        int j = 0;
        while (i < len1 && j < len2) {
            if (a[i] > b[j]) {
                res = min(res, a[i] - b[j]);
                ++j;
            } else if (a[i] < b[j]) {
                if (i < len1 - 1) {
                    if (abs(a[i] - b[j]) < abs(a[i + 1] - b[j])) {
                        res = min(res, abs(a[i] - b[j]));
                        ++j;
                    } else {
                        res = min(res, abs(a[i + 1] - b[j]));
                        ++i;
                    }
                } else {
                    res = min(res, b[j] - a[i]);
                    break;;
                }
            } else {
                return 0;
            }
        }

        return res;
    }
};