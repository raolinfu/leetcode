#include<vector>
using namespace std;
class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
		int ans = 0;
		vector<vector<int>> up(n, vector<int>(n));
		vector<vector<int>> down(n, vector<int>(n));
		vector<vector<int>> left(n, vector<int>(n));
		vector<vector<int>> right(n, vector<int>(n));
		vector<vector<int>> grid(n, vector<int>(n, 1));
		for(auto v: mines){
			grid[v[0]][v[1]] = 0;
		}

		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(i == 0){
					up[i][j] = grid[i][j];
                    ans = max(ans, grid[i][j]);
					continue;
				}
				if(grid[i][j] == 0){
					up[i][j] = 0;
				}else{
					up[i][j] = up[i - 1][j] + 1;
				}
			}
		}
		for(int i = n - 1; i >= 0; i--){
			for(int j = 0; j < n; j++){
				if(i == n - 1){
					down[i][j] = grid[i][j];
                    ans = max(ans, grid[i][j]);
					continue;
				}
				if(grid[i][j] == 0){
					down[i][j] = 0;
				}else{
					down[i][j] = down[i + 1][j] + 1;
				}
			}
		}

		for(int j = 0; j < n; j++){
			for(int i = 0; i < n; i++){
				if(j == 0){
					left[i][j] = grid[i][j];
                    ans = max(ans, grid[i][j]);
					continue;
				}
				if(grid[i][j] == 0){
					left[i][j] = 0;
				}else{
					left[i][j] = left[i][j - 1] + 1;
				}
			}
		}

		for(int j = n - 1; j >= 0; j--){
			for(int i = 0; i < n; i++){
				if(j == n - 1){
					right[i][j] = grid[i][j];
                    ans = max(ans, grid[i][j]);
					continue;
				}
				if(grid[i][j] == 0){
					right[i][j] = 0;
				}else{
					right[i][j] = right[i][j + 1] + 1;
				}
			}
		}


		for(int i = 1; i < n; i++){
			for(int j = 1; j < n; j++){
				ans = max(ans, min(min(up[i][j], down[i][j]), min(left[i][j], right[i][j])));
			}
		}
        return ans;
    }
};
