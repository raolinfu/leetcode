#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

// dp[i]=dp[j] && check(s[j..i−1])
// 状态转移方程
 bool wordBreak(string s, vector<string>& wordDict) {
	unordered_set<string> set;
	for(int i = 0; i < wordDict.size(); i++){
		set.insert(wordDict[i]);
	}
	vector<bool> dp(s.length() + 1, false);
	dp[0] = true;
	for(int i = 1; i <= s.length(); i++){
		for(int j = 1; j < i; j++){
			if(dp[j] && set.find(s.substr(j, i - j)) != set.end())
				{
					dp[i] = true;
					break;
				}
		}
	}
	return dp[s.length()];
 }

int main(){
	string	s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	bool res = wordBreak(s, wordDict);
	return 0;
}
