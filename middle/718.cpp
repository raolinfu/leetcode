#include<vector>
#include<iostream>
using namespace std;
/* 
 *	dp[i][j] nums1[i]和nums[j]结尾的最长子数组 dp[i][j] = dp[i - 1][j - 1]
 * */
int findLength(vector<int>& nums1, vector<int>& nums2) {
	int res = 0;
	int len1 = nums1.size();
	int len2 = nums2.size();
	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	for(int i = 0; i < len1; i++){
		if(nums1[i] == nums2[0]){
			dp[i][0] = 1;
			res = max(res, dp[i][0]);
		}
	}
	for(int j = 0; j < len2; j++){
		if(nums2[j] == nums1[0]){
			dp[0][j] = 1;
			res = max(res, dp[0][j]);
		}
	}
	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			if(nums1[i] == nums2[j]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
				res = max(res, dp[i][j]);
			}
		}
	}

	return res;
}

int main(){
	vector<int> nums1 = {1,2,3,2,1};
	vector<int> nums2 = {3,2,1,4,7};
	int res = findLength(nums1, nums2);
	cout<< res<< endl;
	return 0;
}
