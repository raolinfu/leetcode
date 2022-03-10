#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
		vector<pair<int, int>> need;
		int rows = board.size();
		int cols = board[0].size();
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(changeState(board, i, j))
					need.push_back({i, j});
			}
		}
		for(auto pr: need)
			board[pr.first][pr.second] = 1 - board[pr.first][pr.second];

    }
	bool changeState(vector<vector<int>>& board, int a, int b){
		int cnt = 0;
		for(int i = -1; i <= 1; i++){
			for(int j = -1; j <= 1; j++){
				if(i == 0 && j == 0)
					continue;
				int x = a + i;
				int y = b + j;
				if(x >=0 && x < board.size() && y >= 0 && y < board[0].size() && board[x][y]){
					if(a == 1 && b == 0)
						cout<< x<< " "<< y<< " iiii "<< i<< " "<< j<< "\t";
					cnt++;
				}
			}
		}

		if(board[a][b] == 0)
			return cnt == 3;
		else
			return (cnt < 2 || cnt > 3);
	}
};
int main(){
	vector<vector<int>>board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	Solution solution;
	solution.gameOfLife(board);
	int rows = board.size();
	int cols = board[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout<< board[i][j]<< " ";
		}
		cout<< endl;
	}
	return 0;
}
