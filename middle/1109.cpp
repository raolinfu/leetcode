#include <vector>
using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n, 0);
        for (auto v: bookings) {
            setDiff(ans, v[2], v[0], v[1]);
        }

        for (int i = 1; i < ans.size(); i++)
            ans[i] += ans[i - 1];
        return ans;
    }

    void setDiff(vector<int>& diff, int& v, int& i, int& j) {
        diff[i] += v;
        if (j == diff.size() - 1) {
            return;
        }
        diff[j + 1] -= v;
    }
};
