#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
		int len = s.length();
		if (s[0] == '0')
			return 0;
		for (int i = 1; i < s.length(); i++) {
			if (s[i] == '0' && (s[i - 1] != '1' && s[i - 1] != '2'))
				return 0;
		}
		if (len == 1)
			return 1;
		vector<int> dp(len);
		dp[0] = 1;
		if(atoi(s.substr(0, 2).c_str()) <= 26 && s[1] != '0'){
			dp[1] = 2;
		} else {
			dp[1] = 1;
		}

		for (int i = 2; i < len; i++) {
			if (s[i] == '0' && i - 2 >= 0) {
				dp[i] = dp[i - 2];
			} else if (s[i] >= '1' && s[i] <= '6') {
				dp[i] = dp[i - 1];
				if ((s[i - 1] == '1' || s[i - 1] == '2') && i - 2 >= 0)
					dp[i] += dp[i - 2];
			} else if (s[i] >= '7' && s[i] <= '9') {
				dp[i] = dp[i - 1];
				if (s[i - 1] == '1' && i - 2 >= 0)
					dp[i] += dp[i - 2];
			}
		}

		return dp[len - 1];
    }
};
