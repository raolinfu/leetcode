#include<vector>
#include<iostream>
using namespace std;

void visidIsland(vector<vector<char>>& grid, int i, int j, int &rows, int cols);

int numIslands(vector<vector<char>>& grid) {
	if(grid.size() == 0 || grid[0].size() == 0)
		return 0;
	int rows = grid.size();
	int cols = grid[0].size();
	int res = 0;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(grid[i][j] == '1'){
				res++;
				visidIsland(grid, i, j, rows, cols);	
			}
		}
	}

	return res;
}

void visidIsland(vector<vector<char>>& grid, int i, int j, int &rows, int cols){
	if(i >=0 && i < rows && j >=0 && j < cols){
		if(grid[i][j] == '1'){
			grid[i][j] = '0';
			visidIsland(grid, i + 1, j, rows, cols);
			visidIsland(grid, i, j + 1, rows, cols);
			visidIsland(grid, i - 1, j, rows, cols);
			visidIsland(grid, i, j - 1, rows, cols);
		}
	}

	return;
}

int main(){
	vector<vector<char>> grid = {{'1','1','1','1','0'},
								{'1','0','0','1','0'},
								{'0','1','0','0','0'},
								{'0','0','0','0','0'}};

	int res = numIslands(grid);
	cout<< res<< endl;
}
