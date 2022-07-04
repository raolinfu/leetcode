#include <climits>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
using tiii = tuple<int, int, int>;
struct Cmp {
    bool operator()(const tiii& a, const tiii& b) {
        return std::get<0>(a) > std::get<0>(b);
    }
};

class Solution {
    vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int ans;
        vector<vector<int>> distances(rows, vector<int>(cols, INT_MAX));

        std::priority_queue<tiii, vector<tiii>, Cmp> priq;
        priq.emplace(0, 0, 0);

        while (!priq.empty()) {
            auto [dis, i, j] = priq.top();
            priq.pop();

            if (i == rows - 1 && j == cols - 1) {
                ans = dis;
                break;
            }

            if (dis > distances[i][j]) {
                continue;
            }

            for (int k = 0; k < 4; k++) {
                int r = i + directions[k].first;
                int c = j + directions[k].second;

                if (r >= 0 && r < rows && c >= 0 && c < cols) {
                    if (grid[i][j] == k + 1) {
                        if (distances[r][c] > dis) {
                            distances[r][c] = dis;
                            priq.emplace(dis, r, c);
                        }
                    } else {
                        int distance = dis + 1;
                        if (distances[r][c] > dis) {
                            distances[r][c] = distance;
                            priq.emplace(distance, r, c);
                        }
                    }
                }
            }
        }

        return ans;
    }
};
