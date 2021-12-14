#include<string>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool checkInclusion(string s1, string s2) {
	int len1 = s1.length();
	int len2 = s2.length();
	sort(s1.begin(), s1.end());
	sort(s2.begin(), s2.end());
	cout<< "str1: "<< s1<< endl;
	cout<< "str2: "<< s2<< endl;
	vector<vector<bool>> dp(len1, vector<bool>(len2, false));
	for(int j = 0; j < len2; j++){
		if(s1[0] == s2[j]){
			dp[0][j] = true;
			continue;
		}
		if(j > 0)
			dp[0][j] = dp[0][j - 1];
	}
	for(int i = 1; i < len1; i++){
		for(int j = 1; j < len2; j++){
			dp[i][j] = dp[i][j - 1];
			if(s1[i] == s2[j] && !dp[i][j]){
				dp[i][j] = dp[i - 1][j - 1];
			}
		}
	}
	for(int i = 0; i < len1; i++){
		for(int j = 0; j < len2; j++){
			cout<< dp[i][j]<< " ";
		}
		cout<< endl;
	}

	return dp[len1 - 1][len2 - 1];
}

int main(){
	/* string s1 = "ab";
	 * string s2 = "eidbaooo"; */
	string s1= "ab";
	string s2 = "eidboaoo";
	int res = checkInclusion(s1, s2);
	cout<< res<< endl;
	return 0;
}
