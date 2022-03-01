#include<vector>
#include<queue>
#include<iostream>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		if(grid[0][0] != 0)
            return -1;
		queue<pair<int, int>> q;
		int deep = 1;
		q.push({0, 0});
		grid[0][0] = -1;
		while(!q.empty()){
			int n = q.size();
			for(int k = 0; k < n; k++){
				auto top = q.front();
				if(top.first == grid.size() - 1 && top.second == grid[0].size() - 1)
					return deep;
				for(int i = -1; i <= 1; i++){
					for(int j = -1; j <= 1; j++){
						if(i == 0 && j == 0)
							continue;
						int row = top.first + i;
						int col = top.second + j;
						if(row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 0){
							grid[row][col] = -1;
							q.push({row, col});
						}
					}
				}

				q.pop();
			}
			deep++;
		}

		return -1;
    }
};
