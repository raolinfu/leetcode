#include<string>
#include<vector>
#include<iostream>
using namespace std;
/* 
 *	dp[i][j] 表示分别长度的公共子序列
 *	text1[i] == text1[j] dp[i - 1][j - 1] + 1
 *	max(dp[i -1][j], dp[i][j - 1])
 * */
int longestCommonSubsequence(string text1, string text2) {
	int res = 0;
	int len1 = text1.length();
	int len2 = text2.length();
	vector<vector<int>> dp(len1, vector<int>(len2, 0));
	dp[0][0] = text1[0] == text2[0]? 1: 0;
	for(int i = 1; i < len1; i++){
		if(text1[i] == text2[0]){
			dp[i][0] = 1;
			res = max(res, 1);
		}
		else
			dp[i][0] = dp[i - 1][0];
	}
	for(int j = 1; j < len2; j++){
		if(text1[0] == text2[j]){
			dp[0][j] = 1;
			res = max(res, 1);
		}
		else
			dp[0][j] = dp[0][j - 1];
	}
	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(text1[i] == text2[j])
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			res = max(res, dp[i][j]);
			// cout<< "i: "<< i<< " j:"<<j<< " res: "<< res<< endl;
		}
	}


	return res;
};

int main(){
	/* string text1 = "abcde";
	 * string text2 = "ace"; */
	/* string text1 = "abc";
	 * string text2 = "def"; */
	string text1 = "bsbininm";
	string text2 = "jmjkbkjkv";
	int res = longestCommonSubsequence(text1, text2); 
	cout<< res<< endl;
	return 0;
}
