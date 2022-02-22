#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
		int rows = nums1.size();
		int cols = nums2.size();
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		for(int i = 0; i < cols; i++){
			if(nums1[0] == nums2[i])
				dp[0][i] = 1;
			else if(i > 0)
				dp[0][i] = max(dp[0][i], dp[0][ i - 1]);
		}

		for(int i = 0; i < rows; i++){
			if(nums1[i] == nums2[0])
				dp[i][0] = 1;
			else if(i > 0)
				dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		}

		for(int i = 1; i < rows; i++){
			for(int j = 1; j < cols; j++){
				if(nums1[i] == nums2[j])
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
			}
		}

		return dp[rows - 1][cols - 1];
    }
};
