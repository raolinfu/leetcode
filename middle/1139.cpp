#include <vector>
using namespace std;

struct Count {
    int left = 0;
    int right = 0;
    int top = 0;
    int buttom = 0;
};

class Solution {
public:
    int largest1BorderedSquare(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int res = 0;
        vector<vector<Count>> record(rows, vector<Count>(cols));
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j]) {
                    // left
                    if ( j == 0)
                        record[i][j].left = 1;
                    else
                        record[i][j].left = record[i][j - 1].left + 1;
                    // top
                    if (i == 0)
                        record[i][j].top = 1;
                    else
                        record[i][j].top = record[i - 1][j].top + 1;
                }
            }
        }

        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (grid[i][j]) {
                    // right
                    if (j == cols - 1)
                        record[i][j].right = 1;
                    else
                        record[i][j].right = record[i][j + 1].right + 1;
                    // buttom
                    if (i == rows - 1)
                        record[i][j].buttom = 1;
                    else
                        record[i][j].buttom = record[i + 1][j].buttom + 1;
                }
            }
        }

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int len = min(record[i][j].right, record[i][j].buttom);
                for (int k = 0; k < len; k++) {
                    int r = i + k;
                    int c = j + k;
                    if (r > rows || c > cols)
                        break;
                    int len1 = min(record[r][c].left, record[r][c].top);
                    if (len1 > k)
                        res = max(res, (k + 1) * (k + 1));
                }
            }
        }

        return res;
    }
};