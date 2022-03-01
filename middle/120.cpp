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
				for(int j = 0; j < triangle[i].size(); j++){
					if(j == 0){
						res[j] += triangle[i - 1][j];
					}
					else if(j == triangle[i].size() - 1){
						res[j] += triangle[i - 1][j - 1];
					}else{
						res[j] += min(triangle[i - 1][j - 1], triangle[i - 1][j]);
					}
				}
			}

			for(int i = 1; i < rows; i++){
				ans = min(ans, res[i]);
			}

			return ans;
		}
};
