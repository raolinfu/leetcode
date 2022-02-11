#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>

using namespace std;

vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    vector<int> ans;
	vector<int> tmp;
	bool direction = true;
    int rows = mat.size();
    int cols = mat[0].size();

	for(int d = 0; d < rows + cols - 1; d++){
		tmp.clear();
		int r = d < cols? 0: d - cols + 1;
		int c = d < cols? d: cols - 1; 
		while(r < rows && c >= 0){
			tmp.push_back(mat[r][c]);
			r++;
			c--;
		}
		if(direction){
			std::reverse(tmp.begin(), tmp.end());
		}
		direction = !direction;
		for(auto ele: tmp)
			ans.push_back(ele);
	}

    return ans;
}
void left2right(vector<int>& ans, vector<vector<int>>& mat, int& rows, int& cols, int i, int j){
	while(true){
		i--;
		j++;
		if(i < 0 || j == cols)
			break;
		ans.push_back(mat[i][j]);
	}
}

void right2left(vector<int>& ans, vector<vector<int>>& mat, int& rows, int& cols, int i, int j){
	while(true){
		i++;
		j--;
		if(i == rows || j < 0)
			break;
		ans.push_back(mat[i][j]);
	}
}

int main(int argc, char const *argv[])
{
	// vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}}; 
	vector<vector<int>> mat = {{1,2},{3,4}}; 
	vector<int> ans = findDiagonalOrder(mat);
	for(auto ele: ans)
		cout<< ele<< " ";
    int rows = mat.size();
    int cols = mat[0].size();
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < cols; j++){
		}
	}
    return 0;
}
