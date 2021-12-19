#include<vector>
#include<climits>
#include<utility>
#include<iostream>
using namespace std;

int getDis(pair<int, int>& a, pair<int, int>& b);
void process(vector<vector<int>>& grid, vector<pair<int, int>>& vec, int& rows, int& cols, int i, int j);
int shortestBridge(vector<vector<int>>& grid) {
	int ans = INT_MAX;
	int rows = grid.size();
	int cols = grid[0].size();
	int flag = 0;
	vector<pair<int, int>> vec1;
	vector<pair<int, int>> vec2;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(flag == 0 && grid[i][j]){
				process(grid, vec1, rows, cols, i, j);
				flag = 1;
			}else if(flag == 1 && grid[i][j]){
				process(grid, vec2, rows, cols, i, j);
			}
		}
	}

	for(int i = 0; i < vec1.size(); i++){
		for(int j = 0; j < vec2.size(); j++){
			ans = min(ans, getDis(vec1[i], vec2[j]));
		}
	}
	return ans;
}

int getDis(pair<int, int>& a, pair<int, int>& b){
	return abs(a.first - b.first) + abs(a.second - b.second) - 1;
}

void process(vector<vector<int>>& grid, vector<pair<int, int>>& vec, int& rows, int& cols, int i, int j){
	if(i >= 0 && i < rows && j >=0 && j < cols && grid[i][j]){
		grid[i][j] = 0;
		vec.push_back({i, j});
		process(grid, vec, rows, cols, i + 1, j);
		process(grid, vec, rows, cols, i - 1, j);
		process(grid, vec, rows, cols, i, j + 1);
		process(grid, vec, rows, cols, i, j - 1);
	}
}
int main(){
	// vector<vector<int>>A = {{0,1,0},{0,0,0},{0,0,1}};
	vector<vector<int>>A = {{1,1,1,1,1},{1,0,0,0,1},{1,0,1,0,1},{1,0,0,0,1},{1,1,1,1,1}};
	int ans = shortestBridge(A);
	cout<< ans<< endl;
	return 0;
}
