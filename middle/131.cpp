#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
		vector<vector<string>> ans;
		vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
		for(int i = s.length(); i >= 0; i--){
			for(int j = i; j < s.length(); j++){
				if(i == j){
					dp[i][j] = true;
					continue;
				}
				if(s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1]))
						dp[i][j] = true;
			}
		}
		vector<string> tmp;
		dfs(ans, dp, tmp, s, 0);

		return ans;
    }

	void dfs(vector<vector<string>>& ans, vector<vector<bool>>& dp, vector<string>& tmp, string& s, int idx){
		if(idx == s.length()){
			ans.push_back(tmp);
			return;
		}
		for(int i = idx; i < s.length(); i++){
			if(dp[idx][i]){
				tmp.push_back(s.substr(idx, i - idx + 1));
				dfs(ans, dp, tmp, s, i + 1);
				tmp.pop_back();
			}
		}
	}
};
int main(){
	string str = "adglfdsdf";
	cout<< str.substr(2, 2)<< endl;
	return 0;
}
