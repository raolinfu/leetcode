#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
    unordered_map<int, unordered_set<int>> mp;
    unordered_set<int> st;
    int n;
public:
    bool canCross(vector<int>& stones) {
        if (stones[0] != 0 || stones[1] != 1)
            return false;

        n = *stones.rbegin();
        for (auto& s: stones)
            st.insert(s);

        return dfs(1, 1);
    }

    // 当前位置 之前跳跃数
    bool dfs(int position, int k) {
        if (position == n)
            return true;

        if (position > n || k <= 0 || !st.count(position) || mp[position].count(k))
            return false;

        if (dfs(position + k, k) || dfs(position + k - 1, k - 1) || dfs(position + k + 1, k + 1))
            return true;

        mp[position].insert(k);
        return false;
    }
};
