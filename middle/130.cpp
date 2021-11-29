#include<vector>
#include<utility>
#include<stack>
#include<iostream>
using namespace std;

void process(vector<vector<char>>& board, stack<pair<int, int>> &q, int &rows, int &cols, bool &isRound, int i, int j);
void solve(vector<vector<char>>& board) {
	int rows = board.size();
	int cols = board[0].size();
	stack<pair<int, int>> q;
	bool isRound;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			isRound = true;
			while(!q.empty()){
				q.pop();
			}
			
			/* if(board[i][j] == 'O'){
			 *     cout<< "------------"<< endl;
			 * } */
			process(board, q, rows, cols, isRound, i, j);
			if(isRound){
				while(!q.empty()){
					auto top = q.top();
					board[top.first][top.second] = 'X';
					q.pop();
				}
			}
		}
	}

	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			if(board[i][j] == '1')
				board[i][j] = 'O';
		}
	}
}

void process(vector<vector<char>>& board, stack<pair<int, int>> &q, int &rows, int &cols, bool &isRound, int i, int j){
	if(i >=0 && i < rows && j >=0 && j < cols && board[i][j] == 'O'){
		board[i][j] = '1';
		if(i == 0 || i == rows - 1 || j == 0 || j == cols - 1){
			// cout<< "i:"<< i<< " j:"<< j<< endl;
			isRound = false;
		}
		q.push({i, j});
		process(board, q, rows, cols, isRound, i + 1, j);
		process(board, q, rows, cols, isRound, i - 1, j);
		process(board, q, rows, cols, isRound, i, j + 1);
		process(board, q, rows, cols, isRound, i, j - 1);
		// cout<< "i:"<< i<< " j:"<< j<< " isRound:"<< isRound<< endl;
			
		/* if(isRound){
		 *     board[i][j] = 'X';
		 * } */
	} 
}


int main(){
	vector<vector<char>> board = {
		{'O','X','O','O','X','X','X','O','O','O','O','O','X','O','O','O','O','X','O','X'},
		{'X','O','X','O','O','X','X','O','O','X','O','X','O','X','O','X','X','O','O','O'},
		{'O','X','O','O','O','X','X','X','X','O','O','O','O','O','X','X','X','X','O','X'},
		{'X','X','O','O','O','X','X','O','O','O','X','X','X','O','O','X','O','X','X','O'},
		{'O','X','O','X','X','O','X','O','O','O','X','O','O','X','O','O','O','O','O','X'},
		{'X','O','O','X','O','X','O','O','O','X','X','O','X','O','O','X','O','O','O','O'},
		{'X','O','O','O','X','X','O','O','O','O','O','X','O','O','X','O','O','O','O','X'},
		{'X','O','O','O','X','O','X','X','X','O','X','O','X','X','X','X','O','O','O','X'},
		{'X','O','O','X','O','O','O','X','O','O','O','O','O','O','O','O','O','X','O','X'},
		{'O','O','O','X','O','X','X','X','X','X','X','X','X','X','O','O','O','O','X','O'},
		{'X','O','X','O','X','O','O','X','X','X','O','X','X','O','O','X','X','O','O','O'},
		{'O','X','O','O','X','O','O','O','O','O','O','X','X','X','X','O','O','O','X','O'},
		{'X','O','O','O','X','X','X','O','X','O','O','O','X','O','X','O','X','O','O','X'},
		{'O','O','O','O','X','O','X','X','O','X','O','X','O','X','X','X','X','O','O','O'},
		{'O','X','X','O','O','O','O','X','O','O','X','X','X','O','O','X','X','O','X','O'},
		{'X','O','X','X','X','X','X','X','O','X','X','O','X','O','O','X','O','O','O','X'},
		{'X','O','O','O','X','O','X','O','O','X','O','X','O','O','X','O','O','X','X','X'},
		{'O','O','X','O','O','O','O','X','O','O','X','X','O','X','X','X','O','O','O','O'},
		{'O','O','X','O','O','O','O','O','O','X','X','O','X','O','X','O','O','O','X','X'},
		{'X','O','O','O','X','O','X','X','X','O','O','X','O','X','O','X','X','O','O','O'}};

	/* vector<vector<char>> board = {
	 *     {'X','X','X','X'},
	 *     {'X','O','O','X'},
	 *     {'X','X','O','X'},
	 *     {'X','O','X','X'}}; */

	int rows = board.size();
	int cols = board[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
			cout<< board[i][j]<< " ";
		}
		cout<< endl;
	}
	solve(board);
	// cout<<"-------------";
	/* for(int i = 0; i < rows; i++){
	 *     for(int j = 0; j < cols; j++){
	 *         cout<< board[i][j]<< " ";
	 *     }
	 *     cout<< endl;
	 * } */

	return 0;
}
