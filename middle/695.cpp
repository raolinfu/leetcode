#include<vector>
#include<iostream>
using namespace std;
/* 
 * 访问过的数置为-1
 *
 * */
void process(vector<vector<int>>& grid, int &cur, int &rows, int &cols, int i, int j);
int maxAreaOfIsland(vector<vector<int>>& grid) {
	int res = 0;
	int rows = grid.size();
	int cols = grid[0].size();
	int cur = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(grid[i][j] == 1){
				cur = 0;
				process(grid, cur, rows, cols, i, j);	
				res = max(res, cur);
			}
		}
	}

	return res;
}

void process(vector<vector<int>>& grid, int &cur, int &rows, int &cols, int i, int j){
	if(i >= 0 && i < rows && j >=0 && j < cols){
		if(grid[i][j] == 1){
			grid[i][j] = -1;			
			cur++;
			process(grid, cur, rows, cols, i + 1, j);	
			process(grid, cur, rows, cols, i - 1, j);	
			process(grid, cur, rows, cols, i, j + 1);	
			process(grid, cur, rows, cols, i, j - 1);	
		}
	}
}

int main(){
	vector<vector<int>>grid = {
		{0,0,1,0,0,0,0,1,0,0,0,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,1,1,0,1,0,0,0,0,0,0,0,0},
		{0,1,0,0,1,1,0,0,1,0,1,0,0},
		{0,1,0,0,1,1,0,0,1,1,1,0,0},
		{0,0,0,0,0,0,0,0,0,0,1,0,0},
		{0,0,0,0,0,0,0,1,1,1,0,0,0},
		{0,0,0,0,0,0,0,1,1,0,0,0,0}};
	int res = maxAreaOfIsland(grid);
	cout<< res<< endl;
	return 0;
}
