#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        vector<pair<int, int>> adj{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<pair<int, int>> que;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (!visited[i][j]) {
                    int cmp = grid[i][j];
                    bool isTrue = (cmp == 0 && i > 0 && i < rows - 1 && j > 0 && j < cols - 1);
                    visited[i][j] = true;
                    que.push({i, j});
                    while (!que.empty()) {
                        auto f = que.front();
                        que.pop();
                        for (auto& p: adj) {
                            int row = f.first + p.first;
                            int col = f.second + p.second;
                            if (row >= 0 && row < rows && col >= 0 && col < cols && !visited[row][col] && grid[row][col] == cmp) {
                                visited[row][col] = true;
                                que.push({row, col});
                                if (row == 0 || row == rows - 1 || col == 0 || col == cols - 1)
                                    isTrue = false;
                            }
                        }
                    }

                    ans += isTrue;
                }
            }
        }

        return ans;
    }
};
