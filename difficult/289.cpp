#include<vector>
#include<iostream>
using namespace std;

bool willLive(vector<vector<int>>& board, vector<int> &idx, int i, int j);
bool willDie(vector<vector<int>>& board, vector<int> &idx, int i, int j);

void gameOfLife(vector<vector<int>>& board) {
	vector<int> idx = {-1, 0, 1};
	for(int i = 0; i< board.size(); i++){
		for(int j = 0; j< board[0].size(); j++){
			// 会死亡
			if(board[i][j] == 1 && willDie(board, idx, i, j))
				board[i][j] = -1;
			// 会复活
			else if(board[i][j] == 0 && willLive(board, idx, i, j))
				board[i][j] = 2;
		}
	}

	for(int i = 0; i< board.size(); i++){
		for(int j = 0; j< board[0].size(); j++){
			if(board[i][j] == -1)
				board[i][j] = 0;
			else if(board[i][j] == 2)
				board[i][j] = 1;
		}
	}
}
// 活细胞将死亡
bool willDie(vector<vector<int>>& board, vector<int> &idx, int i, int j){
	int res = 0;
	for(int i1 = 0; i1 < idx.size(); i1++){
		for(int j1 = 0; j1 < idx.size(); j1++){
			if(i1 == 0 && j1 == 0)
				continue;
			int row = i + i1;
			int col = j + j1;
			if(row >= 0 && row < board.size() && col >=0 && col < board[0].size() && abs(board[row][col]) == 1)
				res++;
		}
	}
	return res > 3 || res < 2? true: false;
}
 
// 死细胞将复活
bool willLive(vector<vector<int>>& board, vector<int> &idx, int i, int j){
	int res = 0;
	for(int i1 = 0; i1 < idx.size(); i1++){
		for(int j1 = 0; j1 < idx.size(); j1++){
			if(i1 == 0 && j1 == 0)
				continue;
			int row = i + i1;
			int col = j + j1;
			if(row >= 0 && row < board.size() && col >=0 && col < board[0].size() && abs(board[row][col]) == 1)
				res++;
		}
	}
	return res == 3? true: false;

}

int main(){
	vector<vector<int>> board = {{0,1,0},{0,0,1},{1,1,1},{0,0,0}};
	for(int i = 0; i< board.size(); i++){
		for(int j = 0; j< board[0].size(); j++){
			cout<< board[i][j] << "\t";
		}
		cout<< endl;
	}
	gameOfLife(board);
	cout<< "--------"<< endl;
	for(int i = 0; i< board.size(); i++){
		for(int j = 0; j< board[0].size(); j++){
			cout<< board[i][j] << "\t";
		}
		cout<< endl;
	}

}
