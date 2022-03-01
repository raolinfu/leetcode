#include<vector>
#include<climits>
#include<iostream>
using namespace std;
class Solution{
	public:
		int minimumTotal(vector<vector<int>>& triangle){
			int rows = triangle.size();
			vector<int> res(rows, 0);
			res[0] = triangle[0][0];
			int ans = INT_MAX;
			for(int i = 1; i < rows; i++){
				for(int j = triangle[i].size() - 1; j >= 0; j--){
					if(j == 0){
						res[j] += triangle[i][j];
					}
					else if(j == triangle[i].size() - 1){
						res[j] = res[j - 1] + triangle[i][j];
					}else{
						res[j] = triangle[i][j] + min(res[j - 1], res[j]);
					}
					cout<< i<< " "<< j<< " "<< res[j]<< endl;
				}
				cout<< endl;
			}

			for(int i = 0; i < rows; i++){
				cout<< i<< " "<< res[i]<< endl;
				ans = min(ans, res[i]);
			}

			return ans;
		}
};
int main(){
	vector<vector<int>>triangle = {{2},{3,4},{6,5,7},{4,1,8,3}};
	Solution s;
	cout<< s.minimumTotal(triangle)<< endl;
	return 0;
}
