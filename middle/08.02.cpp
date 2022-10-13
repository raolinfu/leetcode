#include <vector>
using namespace std;
class Solution {
    int rows;
    int cols;
public:
    vector<vector<int>> pathWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> res;
        rows = obstacleGrid.size();
        cols = obstacleGrid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        dfs(obstacleGrid, visited, res, 0, 0);

        return res;
    }

    bool dfs(vector<vector<int>>& obstacleGrid, vector<vector<bool>>& visited, vector<vector<int>>& res, int i, int j) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || obstacleGrid[i][j] == 1) {
            return false;
        }

        visited[i][j] = true;
        res.push_back({i, j});
        if (i == rows - 1 && j == cols - 1) {
            return true;
        }

        if (dfs(obstacleGrid, visited, res, i + 1, j)) {
            return true;
        }

        if (dfs(obstacleGrid, visited, res, i, j + 1)) {
            return true;
        }

        res.pop_back();
        return false;
    }
};