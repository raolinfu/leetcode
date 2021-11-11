#include<string>
#include<iostream>
#include<vector>
using namespace std;
/* 
 * dp[i][j] 表示从i...j的最长回文子序列
 * dp[i][j] = dp[i] == dp[j] 
 * j依赖于i...j-1 递增  i依赖于i+1...j递减
 * */
int longestPalindromeSubseq(string s) {
	int len = s.length();
	vector<vector<int>> dp(len, vector<int>(len, 0));
	for(int i = len - 1; i >= 0; i--){
		for(int j = i; j < len; j++){
			if(j == i){
				dp[i][j] = 1;
				continue;
			}
			if(s[i] == s[j]){
				dp[i][j] = max(dp[i + 1][j - 1] + 2, max(dp[i + 1][j], dp[i][j - 1]));
			}
			else{
				dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
			}
		}
	}

	return dp[0][len - 1];
}

int main(){
	// string s = "bbbab";
	string s = "cbbd";
	int res = longestPalindromeSubseq(s);
	cout<< res<< endl;
	return 0;
}
