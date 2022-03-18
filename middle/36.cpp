#include <vector>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
		vector<unordered_set<int>> row_sets(9, unordered_set<int>());
		vector<unordered_set<int>> col_sets(9, unordered_set<int>());
		vector<vector<unordered_set<int>>> grid_sets(3, vector<unordered_set<int>>(3, unordered_set<int>()));
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				if (board[i][j] == '.')
					continue;
				int n = board[i][j];
				if (row_sets[i].count(n) 
						|| col_sets[j].count(n) 
						|| grid_sets[i / 3][j / 3].count(n))
					return false;
				row_sets[i].insert(n);
				col_sets[j].insert(n); 
				grid_sets[i / 3][j / 3].insert(n);
			}
		}

		return true;
    }
};
