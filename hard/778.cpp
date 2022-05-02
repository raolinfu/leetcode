#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int find(vector<int>& f, int x) {
        if (f[x] == x) {
            return x;
        }
        int fa = find(f, f[x]);
        f[x] = fa;
        return fa;
    }

    void merge(vector<int>& f, int x, int y) {
        int fx = find(f, x), fy = find(f, y);
        f[fx] = fy;
    }

    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> f(n * n);
        for (int i = 0; i < n * n; i++) {
            f[i] = i;
        }

        vector<pair<int, int>> idx(n * n); // 存储每个平台高度对应的位置
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                idx[grid[i][j]] = make_pair(i, j);
            }
        }

        vector<pair<int, int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
        for (int threshold = 0; threshold < n * n; threshold++) {
            auto [i, j] = idx[threshold];
            for (const auto [di, dj]: directions) {
                int ni = i + di, nj = j + dj;
                if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] <= threshold) {
                    merge(f, i * n + j, ni * n + nj);
                }
            }
            if (find(f, 0) == find(f, n * n - 1)) {
                return threshold;
            }
        }
        return -1; // cannot happen
    }
};
// 回溯超时
/* class Solution {
 * private:
 *     int ans;
 *     int rows;
 *     int cols;
 *     vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
 * public:
 *     int swimInWater(vector<vector<int>>& grid) {
 *         ans = INT_MAX;
 *         rows = grid.size();
 *         cols = grid[0].size();
 *
 *         int maxNum = 0;
 *         vector<vector<bool>> visited(rows, vector<bool>(cols, false));
 *
 *         backtrace(grid, visited, maxNum, 0, 0);
 *         return ans;
 *     }
 *
 *     void backtrace(vector<vector<int>>& grid, vector<vector<bool>>& visited, int maxNum, int i, int j) {
 *         if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j])
 *             return;
 *         if (i == rows - 1 && j == cols - 1) {
 *             maxNum = max(maxNum, grid[i][j]);
 *             ans = min(ans, maxNum);
 *             return;
 *         }
 *
 *         visited[i][j] = true;
 *         maxNum = max(maxNum, grid[i][j]);
 *
 *         for (auto& d: direction) {
 *             backtrace(grid, visited, maxNum, i + d.first, j + d.second);
 *         }
 *
 *         visited[i][j] = false;
 *     }
 * }; */
