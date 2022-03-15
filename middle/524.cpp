#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
		string ans;
		for (auto str: dictionary) {
			if (isValid(s, str)) {
				if (ans.length() < str.length()) {
					ans = str;
				} else if (ans.length() == str.length()) {
					ans = ans < str? ans: str;
				}
			}
		}
		/* for (auto str: dictionary) {
		 *     int len = getLlcs(s, str);
		 *     if (len == str.length()) {
		 *         if (ans.length() < len) {
		 *             ans = str;
		 *         } else if(ans.length() == len) {
		 *             ans = ans < str? ans: str;
		 *         }
		 *     }
		 * } */

		return ans;
    }
	bool isValid(string& s1, string& s2) {
		int l1 = 0;
		int l2 = 0;
		while (l1 < s1.length() && l2 < s2.length()) {
			if (s1[l1] == s2[l2]) {
				l1++;
				l2++;
			} else {
				l1++;
			}
		}
		return l2 == s2.length();
	}
	// 用最长公共子序列会超时
	int getLlcs(string& s1, string& s2) {
		int l1 = s1.length();
		int l2 = s2.length();
		int ans = 0;
		vector<vector<int>> dp(l1, vector<int>(l2, 0));
		dp[0][0] = s1[0] == s2[0];
		for (int i = 1; i < l2; i++) {
			dp[0][i] = s1[0] == s2[i];
			dp[0][i] = max(dp[0][i], dp[0][i - 1]);
		}

		for (int i = 1; i < l1; i++) {
			dp[i][0] = s1[i] == s2[0];
			dp[i][0] = max(dp[i][0], dp[i - 1][0]);
		}

		for (int i = 1; i < l1; i++) {
			for (int j = 1; j < l2; j++) {
				if (s1[i] == s2[j] && i - j == 1) {
					dp[i][j] = 2;
					ans = max(ans, dp[i][j]);
					continue;
				}

				if (s1[i] == s2[j]) {
					dp[i][j] = dp[i - 1][j - 1] + 1;
				}
				dp[i][j] = max(dp[i][j], max(dp[i - 1][j], dp[i][j - 1]));
				ans = max(ans, dp[i][j]);
			}
		}
		return ans;
	}
};
