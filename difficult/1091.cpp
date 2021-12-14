#include<vector>
#include<queue>
#include<unordered_map>
#include<climits>
#include<iostream>
#include<utility>
using namespace std;
struct Ele{
	int i;
	int j;
	int distance;
};
struct Comp{
	bool operator()(const Ele& a, const Ele& b){
		return a.distance > b.distance;
	}
};

int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
	int ans = -1;
	int rows = grid.size();
	int cols = grid[0].size();
	priority_queue<Ele, vector<Ele>, Comp> queue;
	vector<vector<int>> dis(rows, vector<int>(cols, INT_MAX));
	
	return ans;
}

void update(priority_queue<Ele>& queue, vector<vector<int>>& grid, vector<vector<int>>& dis, 
		int &rows, int& cols, int i, int j, int distance){
	if(i >=0 && i < rows && j >=0 && j < cols && grid[i][j] == 0){
		dis[i][j] = min(dis[i][j], distance + 1);
	}
}
