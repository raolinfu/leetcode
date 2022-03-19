#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
		int ans = 0;
		int rows = grid.size();
		int cols = grid[0].size();
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				int r1 = i;
				int c1 = j;
				int r2 = i + 2;
				int c2 = j + 2;
				if (r2 < rows && c2 < cols && isValid(grid, r1, c1, r2, c2))
					ans++;
			}
		}

		return ans;
    }
	bool isValid(vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
		unordered_set<int> st;
		for (int i = r1; i <= r2; i++) {
			int s = 0;
			st.clear();
			for (int j = c1; j <= c2; j++) {
				if (grid[i][j] < 1 || grid[i][j] > 9 || st.count(grid[i][j]))
					return false;
				else
					st.insert(grid[i][j]);
				s += grid[i][j];
			}
			if (s != 15)
				return false;
		}
		for (int i = c1; i <= c2; i++) {
			int s = 0;
			for (int j = r1; j <= r2; j++) {
				s += grid[j][i];
			}
			if (s != 15)
				return false;
		}
		int n1 = grid[r1][c1] + grid[r1 + 1][c1 + 1] + grid[r2][c2];
		int n2 = grid[r1][c2] + grid[r1 + 1][c2 - 1] + grid[r2][c1];
		if (n1 != 15 || n2 != 15)
			return false;
		return true;
	}
};
