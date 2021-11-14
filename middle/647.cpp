#include<string>
#include<vector>
#include<iostream>
using namespace std;
/* 
 * 判断dp[i][j] 是否为true s[i] == s[j] && dp[i + 1][j - 1] 
 * */
int countSubstrings(string s) {
	int len = s.length();
	int res = 0;
	vector<vector<bool>> dp(len, vector<bool>(len, false));
	for(int i = 0; i < len; i++){
		dp[i][i] = true;
		res++;
		if(i > 0 && s[i - 1] == s[i]){
			dp[i - 1][i] = true;
			res++;
		}	
	}
	for(int i = len - 1; i >=0; i--){
		for(int j = i + 2; j < len; j++){
			if(s[i] == s[j] && dp[i + 1][j - 1]){
				dp[i][j] = true;
				res++;
			}
		}
	}

	return res;
}

int main(){
	// string s = "aaa";
	string s = "abc";
	int res = countSubstrings(s);
	cout<< res<< endl;
	return 0;
}
