#include <vector>
using namespace std;
using pii = pair<int, int>;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        pii p1 = {0, 0};
        pii p2 = {n - 1, n - 1};
        while (p2.first > p1.first) {
            for (int i = p1.second; i < p2.second; i++) {
                int d = i - p1.second;

                int tmp = matrix[p1.first][p1.second + d];
                matrix[p1.first][p1.second + d] =  matrix[p2.first - d][p1.second];
                matrix[p2.first - d][p1.second] =  matrix[p2.first][p2.second - d];
                matrix[p2.first][p2.second - d] = matrix[p2.first + d][p2.second];
                matrix[p2.first + d][p2.second] = tmp;

                // matrix[p1.first][p1.second + d] = matrix[p2.first + d][p2.second];
                // matrix[p2.first + d][p2.second] = matrix[p2.first][p2.second - d];
                // matrix[p2.first][p2.second - d] = matrix[p2.first - d][p1.second];
                // matrix[p2.first - d][p1.second] = tmp;
            }

            ++p1.first;
            ++p1.second;
            --p2.first;
            --p2.second;
        }

    }
};