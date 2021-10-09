#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> getLeft(vector<vector<char>>& matrix, int &rows, int &cols);
vector<vector<int>> getDown(vector<vector<char>>& matrix, int &rows, int &cols);
int maximalSquare(vector<vector<char>>& matrix) {
	int res = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<int>> left = getLeft(matrix, rows, cols);
	vector<vector<int>> down = getDown(matrix, rows, cols);

	return res;
}

vector<vector<int>> getLeft(vector<vector<char>>& matrix, int &rows, int &cols){
	vector<vector<int>> left;
	for(int i = 0; i < rows; i++)
		left.push_back(vector<int>(cols, 0));
	for(int i = rows - 1; i >=0; i--){
		int cnt = 0;
		for(int j = cols - 1; j >=0; j--){
			if(matrix[i][j] == '1'){
				cnt += 1;
			}
			else{
				cnt = 0;
			}
			left[i][j] = cnt;
		}
	}
	return left;
}
vector<vector<int>> getDown(vector<vector<char>>& matrix, int &rows, int &cols){
	vector<vector<int>> down;
	for(int i = 0; i < rows; i++)
		down.push_back(vector<int>(cols, 0));
	for(int j = cols - 1; j >=0; j--){
		int cnt = 0;
		for(int i = rows - 1; i >=0; i--){
			if(matrix[i][j] == '1'){
				cnt += 1;
			}
			else{
				cnt = 0;
			}
			down[i][j] = cnt;
		}
	}

	return down;
}

vector<vector<int>> getX(vector<vector<int>>& down, int &rows, int &cols){
	vector<vector<int>> x;
	
	return x;
}
void test(int a, int b){
	int c = a - b;
}
int main(){
	vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	int res = maximalSquare(matrix);
	return 0;
}
