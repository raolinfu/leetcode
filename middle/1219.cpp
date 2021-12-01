#include<vector>
#include<iostream>
using namespace std;

void process(vector<vector<int>>& grid, int &rows, int &cols, int &ans, int i, int j, int sum);
int getMaximumGold(vector<vector<int>>& grid) {
	int ans = 0;
	int rows = grid.size();
	int cols = grid[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			process(grid, rows, cols, ans, i, j, 0);
		}
	}

	return ans;
}

void process(vector<vector<int>>& grid, int &rows, int &cols, int &ans, int i, int j, int sum){
	if(i >=0 && i < rows && j >= 0 && j < cols){
		if(grid[i][j] == 0){
			ans = max(ans, sum);
			return;	
		}else if(grid[i][j] > 0){
			sum += grid[i][j];
			grid[i][j] = -grid[i][j];
			// cout<< "sum:"<< sum<< " i:"<< i<< " j:"<< j<< endl;
			process(grid, rows, cols, ans, i + 1, j, sum);
			process(grid, rows, cols, ans, i - 1, j, sum);
			process(grid, rows, cols, ans, i, j + 1, sum);
			process(grid, rows, cols, ans, i, j - 1, sum);
			grid[i][j] = -grid[i][j];
		}
	}
	ans = max(ans, sum);
}
int main(){
	vector<vector<int>> grid = {{0,6,0},{5,8,7},{0,9,0}};
	// vector<vector<int>>grid = {{1,0,7},{2,0,6},{3,4,5},{0,3,0},{9,0,20}};
	int ans = getMaximumGold(grid);
	cout<< ans<< endl;
	return 0;
}
