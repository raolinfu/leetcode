#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        vector<bool> r(rows, false);
        vector<bool> c(cols, false);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    r[i] = true;
                    c[j] = true;
                }
            }
        }
        for (int i = 0; i < rows; i++) {
            if (r[i]) {
                for (int j = 0; j < cols; j++)
                    matrix[i][j] = 0;
            }
        }

        for (int j = 0; j < cols; j++) {
            if (c[j]) {
                for (int i = 0; i < rows; i++)
                    matrix[i][j] = 0;
            }
        }

    }
};