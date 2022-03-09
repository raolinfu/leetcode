#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
		int ans;
		int rows = matrix.size();
		int cols = matrix[0].size();
		vector<vector<int>> grid(rows, vector<int>(cols));
		for(int i = 0; i < rows; i++){
			for(int j = 0; j < cols; j++){
				if(i == 0)
					grid[i][j] = matrix[i][j] == '1'? 1: 0;
				else if(matrix[i][j] == '0'){
					grid[i][j] = 0;
				}
				else if(matrix[i][j] == '1'){
					grid[i][j] = grid[i - 1][j] + 1;
				}
			}
		}

		for(int i = 0; i < rows; i++){
			int tmp = getMaxSquire(grid[i]);
			ans = max(ans, tmp);
		}

		return ans;
    }

	int getMaxSquire(vector<int>& nums){
		int ans = 0;
		int i = 0;
		vector<int> stk{-1};
		while(stk.size() > 0 && i < nums.size()){
			while(stk.size() > 1 && nums[i] < nums[stk.back()]){
				int idx = stk.back();
				stk.pop_back();
				int len = i - stk.back() - 1;
				if(len >= nums[idx])
					ans = max(ans, nums[idx] * nums[idx]);
			}

			stk.push_back(i);
			i++;
		}
		while(stk.size() > 1){
			int idx = stk.back();
			stk.pop_back();
			int len = i - stk.back() - 1;
			if(len >= nums[idx])
				ans = max(ans, nums[idx] * nums[idx]);
		}

		return ans;
	}
};
int main(){
	Solution sol;
	vector<vector<char>> matrix = {{'1','0','1','0','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','0','1','0'}};
	int ans = sol.maximalSquare(matrix);
	cout<< ans<< endl;
	return 0;
}
