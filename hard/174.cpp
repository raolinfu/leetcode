/* 
 *	地下城与勇士
 *	dp[i][j]为到终点最少血量
 * */
#include<iostream>
#include<vector>
using namespace std;
int calculateMinimumHP(vector<vector<int>>& dungeon) {
	int rows = dungeon.size();
	int cols = dungeon[0].size();
	vector<vector<int>> dp;
	for(int i = 0; i < rows; i++){
		dp.push_back(vector<int>(cols));
	}
	dp[rows - 1][cols - 1] = dungeon[rows - 1][cols - 1] > 0? 1: -dungeon[rows - 1][cols - 1] + 1;
	for(int i = rows - 2; i >= 0; i--){
		if(dungeon[i][cols - 1] < 0){
			dp[i][cols - 1]	= dp[i + 1][cols - 1] - dungeon[i][cols - 1];
		}else if(dungeon[i][cols - 1] >= dp[i + 1][cols - 1]){
			dp[i][cols - 1] = 1;
		}else{
			dp[i][cols - 1] = dp[i + 1][cols - 1] - dungeon[i][cols - 1];
		}
	}
	for(int j = cols - 2; j >=0; j--){
		if(dungeon[rows - 1][j] < 0){
			dp[rows - 1][j] = dp[rows - 1][j + 1] - dungeon[rows - 1][j];
		}else if(dungeon[rows - 1][j] >= dp[rows - 1][j + 1]){
			dp[rows - 1][j] = 1;
		}else{
			dp[rows - 1][j] = dp[rows - 1][j + 1] - dungeon[rows - 1][j];
		}
	}

	for(int i = rows - 2; i >= 0; i--){
		for(int j = cols - 2; j >= 0; j--){
			int minNum = min(dp[i][j + 1], dp[i + 1][j]);
			if(dungeon[i][j] < 0){
				dp[i][j] = minNum - dungeon[i][j];
			}else if(dungeon[i][j] >= minNum){
				dp[i][j] = 1;
			}else{
				dp[i][j] = minNum - dungeon[i][j];
			}
		}
	}

	return dp[0][0];
}

int main(){
	vector<vector<int>> matrix ={{-2,-3,3},{-5,-10,1},{10,30,-5}};
	int res = calculateMinimumHP(matrix);
	cout<< res<< endl;
	return 0;
}
