#include<vector>
#include<climits>
#include<iostream>
using namespace std;

int minFallingPathSum(vector<vector<int>>& matrix) {
	int ans = INT_MAX;
	int rows = matrix.size();
	int cols = matrix[0].size();
	for(int i = 1; i < rows; i++){
		for(int j = 0; j < cols; j++){
			int tmp = matrix[i - 1][j];
			if(j + 1 < cols){
				tmp = min(tmp, matrix[i - 1][j + 1]);
			}
			if(j - 1 >= 0){
				tmp = min(tmp, matrix[i - 1][j - 1]);
			}

			matrix[i][j] += tmp;
		}
	}

	for(int j = 0; j < cols; j++){
		ans = min(ans, matrix[rows - 1][j]);
	}

	return ans;
}

int main(){
	vector<vector<int>>matrix = {{-19,57},{-40,-5}};
	// vector<vector<int>>matrix = {{2,1,3},{6,5,4},{7,8,9}};
	int ans = minFallingPathSum(matrix);
	cout<< ans<< endl;
	return 0;
}
