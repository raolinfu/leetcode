#include<vector>
#include<stack>
#include<iostream>
using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
	if(matrix.size() == 0 || matrix[0].size() == 0)
		return 0;
	int res = 0;
	int rows = matrix.size();
	int cols = matrix[0].size();
	vector<vector<int>> dp;
	for(int r = 0; r < rows; r++){
		dp.push_back(vector<int>(cols));
	}
	for(int c = 0; c < cols; c++)
		dp[0][c] = matrix[0][c] == '1'? 1: 0;
	for(int c = 0; c < cols; c++){
		for(int r = 1; r < rows; r++){
			dp[r][c] = matrix[r][c] == '1'? dp[r - 1][c] + 1: 0;
		}
	}
	for(int i = 0; i < rows; i++){
		stack<int> st;
		st.push(-1);
		for(int j = 0; j < cols; j++){
			while(!st.empty() && dp[i][st.top()] >= dp[i][j]){
				int pre = st.top();
				int comp = dp[i][pre] * (j - pre);
				res = max(res, comp);
				st.pop();
			}	
			st.push(j);
		}
		if(!st.empty()){
			while(!st.empty()){
				int j = st.top();
				st.pop();
				if(!st.empty()){
					int comp = dp[i][j] * (j - st.top());
					res = max(res, comp);
				}
			}
		}	
	}

	return res;
}

int main(){
	vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	int res = maximalRectangle(matrix);
	cout<< res<< endl;

	return 0;
}
