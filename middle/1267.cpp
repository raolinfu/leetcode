#include <vector>
using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<bool> rowFlags(rows, false);
        vector<bool> colFlags(cols, false);
        for (int i = 0; i < rows; i++) {
            int cnt = 0;
            for (int j = 0; j < cols; j++) {
                cnt += grid[i][j];
            }
            if (cnt > 1)
                rowFlags[i] = true;
        }

        for (int j = 0; j < cols; j++) {
            int cnt = 0;
            for (int i = 0; i < rows; i++) {
                cnt += grid[i][j];
            }
            if (cnt > 1)
                colFlags[j] = true;
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] && (rowFlags[i] || colFlags[j]))
                    ans++;
            }
        }

        return ans;
    }
};
