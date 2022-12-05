#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // 超时
    bool findWhetherExistsPath(int n, vector<vector<int>>& graph, int start, int target) {
        vector<vector<int>> g(n, vector<int>());
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<bool> seen(n, false);
        for (auto& v: graph) {
            g[v[0]].push_back(v[1]);
        }

        queue<int> que;
        que.push(start);

        while (!que.empty())
        {
            int i = que.front();
            if (i == target)
                return true;
            que.pop();
            if (seen[i]) {
                continue;;
            }
            seen[i] = true;
            for (auto& j: g[i]) {
                if (!visited[i][j]) {
                    que.push(j);
                    visited[i][j] = true;
                }
            }
        }
        
        return false;
    }
};