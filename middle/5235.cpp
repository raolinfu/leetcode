#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans(2, vector<int>());
        unordered_map<int, pair<int, int>> mp;
        for (auto v: matches) {
            int win = v[0];
            int lose = v[1];
            if (!mp.count(win)) {
                mp.insert({win, {1, 0}});
            } else {
                mp[win].first++;
            }

            if (!mp.count(lose)) {
                mp.insert({lose, {0, 1}});
            } else {
                mp[lose].second++;
            }
        }
        for (auto iter: mp) {
            if (iter.second.second == 0) {
                ans[0].push_back(iter.first);
            } else if (iter.second.second == 1) {
                ans[1].push_back(iter.first);
            }
        }
        sort(ans[0].begin(), ans[0].end());
        sort(ans[1].begin(), ans[1].end());
        
        return ans;
    }
};
