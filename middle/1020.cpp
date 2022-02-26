#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
		int rows = grid.size();
		int cols = grid[0].size();
		int total = 0;
		int cnt = 0;
		queue<pair<int, int>> q;
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(grid[i][j] == 1){
					total++;
					if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1){
						grid[i][j] = -1;
						q.push({i, j});
						cnt++;
					}
				}
			}
		}
		while(!q.empty()){
			auto [i, j] = q.front();
			if(isValid(grid, rows, cols, i - 1, j)){
				q.push({i - 1, j});
				grid[i - 1][j] = -1;
				cnt++;
			}
			if(isValid(grid, rows, cols, i + 1, j)){
				q.push({i + 1, j});
				grid[i + 1][j] = -1;
				cnt++;
			}
			if(isValid(grid, rows, cols, i, j - 1)){
				q.push({i, j - 1});
				grid[i][j - 1] = -1;
				cnt++;
			}
			if(isValid(grid, rows, cols, i, j + 1)){
				q.push({i, j + 1});
				grid[i][j + 1] = -1;
				cnt++;
			}

			q.pop();
		}

		return total - cnt;
    }
	bool isValid(vector<vector<int>>& grid, int& rows, int& cols, int i, int j){
		if(i >= 0 && i < rows && j >= 0 && j < cols && grid[i][j] == 1 ){
			return true;
		}
		return false;
	}
};
int main(){
	Solution s;
	vector<vector<int>>grid = {{0,0,0,0},{1,0,1,0},{0,1,1,0},{0,0,0,0}};
	int ans = s.numEnclaves(grid);
	cout<< ans<< endl;
	return 0;
}
