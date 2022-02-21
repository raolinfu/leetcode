#include<vector>
#include<queue>
#include<iostream>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
		int ans = 0;
		int cnt = 0;
		int total = 0;
		int rows = grid.size();
		int cols = grid[0].size();
		int fresh = 0;
		queue<pair<int, int>> q;

		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(grid[i][j] != 0)
					total++;
				if(grid[i][j] == 2){
					q.push({i, j});
					cnt++;
				}
				else if(grid[i][j] == 1){
					fresh++;
				}
			}
		}
		if(cnt == 0 && fresh != 0)
			return -1;
		else if(cnt == 0 && fresh == 0){
			return 0;
		}

		while(!q.empty()){
			int size = q.size();
			for(int k = 0; k < size; k++){
				auto [i, j] = q.front();
				process(grid, q, i + 1, j, cnt);
				process(grid, q, i - 1, j, cnt);
				process(grid, q, i, j + 1, cnt);
				process(grid, q, i, j - 1, cnt);
				q.pop();
			}
			ans++;
		}

		return cnt == total? ans - 1: -1;
    }

    void process(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i, int j, int& cnt) {
		if(i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && grid[i][j] == 1){
			grid[i][j] = 2;
			q.push({i, j});
			cnt++;
		}
	}
};
int main(){
	Solution sol;
	vector<vector<int>>grid = {{2,1,1},{1,1,0},{0,1,1}};
	cout<< sol.orangesRotting(grid)<< endl;
	return 0;
}
