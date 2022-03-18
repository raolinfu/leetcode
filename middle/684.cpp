#include <vector>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
class Solution {
public:
    int Find(vector<int>& parent, int index) {
        if (parent[index] != index) {
            parent[index] = Find(parent, parent[index]);
        }
        return parent[index];
    }

    void Union(vector<int>& parent, int index1, int index2) {
        parent[Find(parent, index1)] = Find(parent, index2);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for (int i = 1; i <= n; ++i) {
            parent[i] = i;
        }
        for (auto& edge: edges) {
            int node1 = edge[0], node2 = edge[1];
            if (Find(parent, node1) != Find(parent, node2)) {
                Union(parent, node1, node2);
            } else {
                return edge;
            }
        }
        return vector<int>{};
    }
};


/* class Solution {
 * public:
 *     // 并查集
 *     vector<int> findRedundantConnection(vector<vector<int>>& edges) {
 *         int n = edges.size();
 *         vector<vector<int>> graph(n, vector<int>());
 *         vector<bool> visited(n, false);
 *         vector<int> path;
 *         vector<int> ans;
 *         for (int i = 0; i < n; i++) {
 *             int n1 = edges[i][0];
 *             int n2 = edges[i][1];
 *             graph[n1].push_back(n2);
 *             graph[n2].push_back(n1);
 *         }
 *         dfs(graph, visited, path, 0);
 *         for (int i = n - 1; i >=0 ;i--) {
 *             int n1 = edges[i][0];
 *             int n2 = edges[i][1];
 *             auto p1 =  std::make_pair(n1, n2);
 *             auto p2 =  std::make_pair(n2, n1);
 *             if (set.count(p1) || set.count(p2)) {
 *                 ans = edges[i];
 *                 break;
 *             }
 *         }
 *
 *         return ans;
 *     }
 *
 *     void dfs(vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, int node) {
 *
 *         for (auto i: graph[node]) {
 *             if (!visited[i]) {
 *                 visited[i] = true;
 *                 path.push_back(i);
 *                 dfs(graph, visited, path, i);
 *                 path.pop_back();
 *             } else {
 *                 if (path.size() > 1 && i != path[path.size() - 2]) {
 *                     set.insert({i, path.back()});
 *                     for (int j = path.size() - 1; j >= 1; j--) {
 *                         if (path[j] == i) {
 *                             break;
 *                         }
 *                         set.insert({path[j], path[j - 1]});
 *                     }
 *                     return;
 *                 }
 *             }
 *         }
 *     }
 *
 * private:
 *     set<pair<int, int>> set;
 * }; */
