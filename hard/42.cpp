#include <functional>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using pii = pair<int, int>;

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        int n = height.size();
        if (n <= 2)
            return ans;
        std::priority_queue<pii, vector<pii>, std::greater<pii>> pri_que;
        vector<bool> visited(n, false);
        vector<int> dirs{-1, 1};
        pri_que.push({height[0], 0});
        pri_que.push({height[n - 1], n - 1});
        visited[0] = true;
        visited[n - 1] = true;

        while (!pri_que.empty()) {
            auto cur = pri_que.top();
            pri_que.pop();
            for (int step: dirs) {
                int idx = step + cur.second;
                if (idx >= 0 && idx < n && !visited[idx]) {
                    visited[idx] = true;
                    if (height[idx] < cur.first) {
                        ans += cur.first - height[idx];
                    }
                    int tmp = max(height[idx], cur.first);
                    pri_que.push({tmp, idx});
                }
            }
        }

        return ans;
    }
};
