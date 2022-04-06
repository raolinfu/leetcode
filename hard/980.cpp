#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:
    int ans = 0;
    int count = 0;
    int rows;
    int cols;
    int a1;
    int b1;
    int a2;
    int b2;
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        vector<pair<int, int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 1) {
                    a1 = i;
                    b1 = j;
                    continue;
                }

                if (grid[i][j] == 2) {
                    a2 = i;
                    b2 = j;
                    continue;
                }

                if (grid[i][j] == 0) {
                    count++;
                    continue;
                }
            }
        }

        int cnt = 0;
        backtrace(grid, visited, direction, a1, b1, cnt);

        return ans;
    }

    void backtrace(vector<vector<int>>& grid, vector<vector<bool>>& visited, vector<pair<int, int>>& direction, int i, int j, int& cnt) {
        if (i < 0 || i >= rows || j < 0 || j >= cols || visited[i][j] || grid[i][j] == -1)
            return;
        if (i == a2 && j == b2) {
            if (cnt - 1 == count)
                ans++;
            return;
        }
        visited[i][j] = true;
        ++cnt;
        for (auto& p: direction) {
            int row = i + p.first;
            int col = j + p.second;
            backtrace(grid, visited, direction, row, col, cnt);
        }

        --cnt;
        visited[i][j] = false;
    }
};
