#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> ans;
        int rows = 8;
        int cols = 8;
        vector<vector<bool>> grid(rows, vector<bool>(cols, false));
        vector<pair<int, int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}, 
                                    {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
        for (auto& q: queens) {
            grid[q[0]][q[1]] = true;
        }

        int x = king[0];
        int y = king[1];
        for (auto& p: direction) {
            int i = x + p.first;
            int j = y + p.second;
            while (i >=0 && i < rows && j >= 0 && j < cols) {
                if (grid[i][j]) {
                    ans.push_back({i, j});
                    break;
                }
                i += p.first;
                j += p.second;
            }
        }


        return ans;
    }
};
