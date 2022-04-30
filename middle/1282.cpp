#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < groupSizes.size(); i++)
            mp[groupSizes[i]].emplace_back(i);

        for (auto [k, v]: mp) {
            int i = 0;
            while (i < v.size()) {
                vector<int> tmp;
                for (int j = 0; j < k; j++) {
                    tmp.push_back(v[i]);
                    i++;
                }
                ans.push_back(std::move(tmp));
            }
        }

        return ans;
    }
};
