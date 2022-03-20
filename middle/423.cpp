#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string originalDigits(string s) {
		string ans;
		vector<int> dp(10, 0);
		int o_num = 0;
		int g_num = 0;
		int w_num = 0;
		int u_num = 0;
		int x_num = 0;
		int i_num = 0;
		int s_num = 0;
		int z_num = 0;
		int f_num = 0;
		int h_num = 0;
		for (auto ch: s) {
			if (ch == 'z')
				z_num++;
			if (ch == 'w')
				w_num++;
			if (ch == 'u')
				u_num++;
			if (ch == 'x')
				x_num++;
			if (ch == 'f')
				f_num++;
			if (ch == 'o')
				o_num++;
			if (ch == 's')
				s_num++;
			if (ch == 'g')
				g_num++;
			if (ch == 'i')
				i_num++;
			if (ch == 'h')
				h_num++;
		}
		dp[0] = z_num;
		dp[2] = w_num;
		dp[4] = u_num;
		dp[6] = x_num;
		dp[8] = g_num;
		dp[3] = h_num - dp[8];
		dp[1] = o_num - dp[0] - dp[2] - dp[4];
		dp[5] = f_num - dp[4];
		dp[7] = s_num - dp[6];
		dp[9] = i_num - dp[8] - dp[5] - dp[6];
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < dp[i]; j++) {
				ans += '0' + i;
			}
		}

		return ans;
    }
};
