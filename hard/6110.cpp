#include <vector>
#include <cmath>
#include <queue>
#include <tuple>
using namespace std;
using tiii = tuple<int, int, int>;

struct Cmp {
    bool operator()(const tiii& a, const tiii& b) {
        return std::get<0>(a) > std::get<0>(b);
    }
};

class Solution {
    vector<pair<int, int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int countPaths(vector<vector<int>>& grid) {
        int mode = pow(10, 9) + 7;
        int ans = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<int>> mem(rows, vector<int>(cols, 1));
        std::priority_queue<tiii, vector<tiii>, Cmp> priq;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                priq.push({grid[i][j], i, j});
            }
        }

        while (!priq.empty()) {
            auto [val, i, j] = priq.top();
            priq.pop();

            for (auto& d: directions) {
                int r = i + d.first;
                int c = j + d.second;
                if ( r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] < grid[i][j]) {
                    mem[i][j] += mem[r][c];
                    mem[i][j] %= mode;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                ans += mem[i][j];
                ans %= mode;
            }
        }
        
        return ans;
    }
};
