#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution {
public:
	// 公共子序列为pattern
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
		vector<bool> ans;
		for(auto str: queries)
			ans.push_back(isValid(str, pattern));

		return ans;
    }
	bool isValid(string& str1, string& str2){
		int cnt1 = 0;
		int cnt2 = 0;
		int rows = str1.length();
		int cols = str2.length();
		int l = 0;
		for(auto ch: str1){
			if(std::isupper(ch))
				cnt1++;
		}
		for(auto ch: str2){
			if(std::isupper(ch))
				cnt2++;
		}
		if(cnt1 > cnt2)
			return false;
		vector<vector<int>> dp(rows, vector<int>(cols, 0));
		if(str1[0] == str2[0])
			dp[0][0] = 1;
		for(int i = 1; i < rows; i++){
			if(str1[i] == str2[0])
				dp[i][0] = 1;
			else
				dp[i][0] = dp[i - 1][0];
		}
		for(int i = 1; i < cols; i++){
			if(str1[0] == str2[i])
				dp[0][i] = 1;
			else
				dp[0][i] = dp[0][i - 1];
		}
		for(int i = 1; i < rows; i++){
			for(int j = 1; j < cols; j++){
				if(str1[i] == str2[j])
					dp[i][j] = dp[i - 1][j - 1] + 1;
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
				l = max(dp[i][j], l);
			}
		}

		return l == str2.length();
	}
};
int main(){
	vector<string>queries = {"FooBar","FooBarTest","FootBall","FrameBuffer","ForceFeedBack"};
	string pattern = "FB";
	Solution sol;
	auto ans = sol.camelMatch(queries, pattern);
	for(auto s: ans)
		cout<< s<< " ";
	cout<< endl;
	return 0;
}
