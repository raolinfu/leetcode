#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.length();
		int maxLen = 1;
		int begin = 0;
		vector<vector<bool>> dp(n, vector<bool>(n, false));
		for (int i = 0; i < n; i++)
			dp[i][i] = true;
		for (int L = 2; L <= n; L++) {
			for (int i = 0; i < n; i++) {
				int j = i + L - 1;
				if (j >= n)
					break;
				if (s[i] == s[j]) {
					if (L == 2)
						dp[i][j] = true;
					else
						dp[i][j] = dp[i + 1][ j - 1];
				}

				if (dp[i][j] && (j - i + 1) > maxLen) {
					begin = i;
					maxLen = j - i + 1;
				}
			}
		}


		return s.substr(begin, maxLen);
    }
};

int main(){
	string str;
	cin>> str;
	Solution sol;
	cout<< sol.longestPalindrome(str)<< endl;

	return 0;
}
