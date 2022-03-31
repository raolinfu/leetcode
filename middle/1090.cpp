#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        int ans = 0;
        int n = values.size();
        unordered_map<int, int> mp;
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            q.push({values[i], labels[i]});
        }

        int cnt = 0;
        while (!q.empty() && cnt < numWanted) {
            auto [v, l] = q.top();    
            if (mp[l] < useLimit) {
                ans += v;
                ++mp[l];
                ++cnt;
            }

            q.pop();
        }

        return ans;
    }
};
