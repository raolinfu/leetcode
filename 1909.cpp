#include<vector>
#include<iostream>
using namespace std;
void process(vector<vector<int>>& grid1, bool &valid, int &rows, int &cols, int i, int j);
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
	int res = 0;
	int rows = grid1.size();
	int cols = grid1[0].size();
	bool valid;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(grid2[i][j]){
				grid1[i][j] = grid1[i][j] == 1? -2: 2;
			}
		}
	}
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(abs(grid1[i][j]) == 2){
				valid = true;
				process(grid1, valid, rows, cols, i, j);
				res = valid? res + 1: res;
			}
		}
	}

	return res;
}

void process(vector<vector<int>>& grid1, bool &valid, int &rows, int &cols, int i, int j){
	if(i >= 0 && i < rows && j >= 0 && j < cols && abs(grid1[i][j]) == 2){
		if(grid1[i][j] == 2 && valid)
			valid = false;
		grid1[i][j] = 3;
		process(grid1, valid, rows, cols, i + 1, j);
		process(grid1, valid, rows, cols, i - 1, j);
		process(grid1, valid, rows, cols, i, j + 1);
		process(grid1, valid, rows, cols, i, j - 1);
	}
}

int main(){
	/* vector<vector<int>> grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
	 * vector<vector<int>> grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}}; */
	vector<vector<int>>grid1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
	vector<vector<int>>grid2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};
	int res = countSubIslands(grid1, grid2);
	cout<< res<< endl;
	return 0;
}
