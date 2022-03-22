#include <vector>
using namespace std;
class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {
		matrix_sum = matrix;
		for (int i = 0; i < matrix.size(); i++) {
			for (int j = 0; j < matrix[0].size(); j++) {
				if (j == 0)
					continue;
				else
					matrix_sum[i][j] += matrix_sum[i][j - 1];
			}
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
		int ans = 0;
		if (col1 > 0) {
			for (int i = row1; i <= row2; i++) {
				ans += matrix_sum[i][col2] - matrix_sum[i][col1 - 1];
			}
		} else {
			for (int i = row1; i <= row2; i++) {
				ans += matrix_sum[i][col2];
			}
		}

		return ans;
    }
private:
	vector<vector<int>> matrix_sum;
};
