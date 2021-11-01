#include<string>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

void process(string &s, string &t, int &res, unordered_map<char, int> &set1, unordered_map<char, int>&set2, int i, int n);
int numDistinct(string s, string t) {
	// 保存字母数量 set2是目标的 set1是源字符串的
	/* char set1[26] = {0};
	 * char set2[26] = {0}; */
	unordered_map<char, int> set1;
	unordered_map<char, int> set2;
	for(char ch: t){
		set2[ch - 'a']++;
	}
	for(char ch: s){
		if(set2[ch - 'a'])
			set1[ch - 'a']++;
	}
	int res = 0;
	process(s, t, res, set1, set2, 0, 0);
	return res;
}
/*
 * i代表s已经匹配了i位
 * n代表已经有n位匹配成功
 * 超时
 * 用map剪枝还是超时
 * */
void process(string &s, string &t, int &res, unordered_map<char, int> &set1,  unordered_map<char, int> &set2, int i, int n){
	// 如果源字符串字母比目标都少了 后面不需要匹配了
	if(set2[t[n]] > set1[t[n]])
		return;
	if(n == t.length()){
		res++;
		return;
	}
	for(int j = i; j < s.length(); j++){
		if(s.length() - j < t.length() - n)
			return;
		if(s[j] == t[n]){
			set2[t[n] - 'a']--;
			set1[t[n] - 'a']--;
			process(s, t, res, set1, set2, j + 1, n + 1);
			set2[t[n] - 'a']++;
			set1[t[n] - 'a']++;
		}
	}

}
/* 
 * 动态规划
 * s[i:] t[j:]的种数
 * */
int numDistinct1(string s, string t) {
	int m = s.length(), n = t.length();
	if (m < n) {
		return 0;
	}
	vector<vector<long>> dp(m + 1, vector<long>(n + 1));
	for (int i = 0; i <= m; i++) {
		dp[i][n] = 1;
	}
	for (int i = m - 1; i >= 0; i--) {
		char sChar = s.at(i);
		for (int j = n - 1; j >= 0; j--) {
			char tChar = t.at(j);
			if (sChar == tChar) {
				dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
			} else {
				dp[i][j] = dp[i + 1][j];
			}
		}
	}
	return dp[0][0];
}


int main(){
	/* string s = "rabbbit";
	 * string t = "rabbit"; */
	/* string s = "babgbag";
	 * string t = "bag"; */
	string s = "daacaedaceacabbaabdccdaaeaebacddadcaeaacadbceaecddecdeedcebcdacdaebccdeebcbdeaccabcecbeeaadbccbaeccbbdaeadecabbbedceaddcdeabbcdaeadcddedddcececbeeabcbecaeadddeddccbdbcdcbceabcacddbbcedebbcaccac";
	string t = "ceadbaa";
	int res = numDistinct(s, t);
	cout << res<< endl;
	res = numDistinct1(s, t);
	cout << res<< endl;
	return 0;
}
