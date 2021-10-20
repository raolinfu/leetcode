#include<string>
#include<vector>
#include<iostream>

using namespace std;
bool process(string &s1, string &s2, string &s3, int n1, int n2, int n3, bool &isFirstStr);
bool isInterleave(string s1, string s2, string s3) {
	if(s1.length() + s2.length() != s3.length())
		return false;
	bool isFirstStr = true;
	bool res1 =	process(s1, s2, s3, 0, 0, 0, isFirstStr); 
	isFirstStr = false;
	bool res2 =	process(s1, s2, s3, 0, 0, 0, isFirstStr); 
	return res1 || res2;
}
/* 
 * 超时
 * */
bool process(string &s1, string &s2, string &s3, int n1, int n2, int n3, bool &isFirstStr){
	//  终结条件 
	if(n1 == s1.length() && n2 == s2.length() && n3 == s3.length())
		return true;
	if(isFirstStr){
		for(int step = 1; step <= s1.length() - n1; step++){
			string sub1 = s1.substr(n1, step);
			string sub3 = s3.substr(n3, step);
			if(sub1 == sub3){
				isFirstStr = false;
				if(process(s1, s2, s3, n1 + step, n2, n3 + step, isFirstStr)){
					return true;
				}	
				isFirstStr = true;
				continue;
			}
			return false;
		}
	}else{
		for(int step = 1; step <= s2.length() - n2; step++){
			string sub2 = s2.substr(n2, step);
			string sub3 = s3.substr(n3, step);
			if(sub2 == sub3){
				isFirstStr = true;
				if(process(s1, s2, s3, n1, n2 + step, n3 + step, isFirstStr)){
					return true;
				}	
				isFirstStr = false;
				continue;
			}
			return false;
		}
	}

	return false;
}

/* 
 * 动态规划 dp[i][j]表示s1的前i个和s2的前j个和s3的前i + j个匹配
 * */
bool isInterleave1(string s1, string s2, string s3) {
	vector<vector<bool>> dp;	
	for(int i = 0; i <= s1.length(); i++){
		dp.push_back(vector<bool>(s2.length() + 1, 0));
	}
	dp[0][0] = true;
	for(int i = 0; i <= s1.length(); i++){
		if(s1.substr(0, i) == s3.substr(0, i)){
			dp[i][0] = true;
			continue;
		}
		break;
	}
	for(int j = 0; j <= s2.length(); j++){
		if(s2.substr(0, j) == s3.substr(0, j)){
			dp[0][j] = true;
			continue;
		}
		break;
	}
	for(int i = 1; i <= s1.length(); i++){
		for(int j = 1; j <= s2.length(); j++){
			if((dp[i - 1][j] && s1[i - 1] == s3[i + j - 1]) 
					|| (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]))
				dp[i][j] = true;

		}
	}
	return dp[s1.length()][s2.length()];
}
int main(){
	/* string s1 = "aabcc";
	 * string s2 = "dbbca";
	 * string s3 = "aadbbcbcac"; */
	string s1 = "ac";
	string s2 = "da";
	string s3 = "adca";
	string s = "";
	cout << s.length()<< endl;
	/* string s1 = "aabcc";
	 * string s2 = "dbbca";
	 * string s3 = "aadbbbaccc"; */
	bool res = isInterleave(s1, s2, s3);
	cout<< res<< endl;

	res = isInterleave1(s1, s2, s3);
	cout<< res<< endl;
	return 0;
}
