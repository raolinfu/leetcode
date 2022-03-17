#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
		vector<string> ans;
		vector<string> tmp;
		dfs(ans, s, tmp, "", 0);

		return ans;
    }

	void dfs(vector<string>& ans, string& s, vector<string>& tmp, string str, int idx) {
		if (tmp.size() > 4 || atoi(str.c_str()) > 255) {
			return;
		}

		if (idx == s.length() && tmp.size() == 4) {
			string a;
			for (int i = 0; i < 4; i++) {
				if (i != 3)
					a += tmp[i] + '.';
				else
					a += tmp[i];
			}
			ans.push_back(a);
			return;
		}

		for (int i = idx; i < s.length(); i++) {
			str += s[i];
			if (str.length() > 1 && str[0] == '0')
				return;

			if (std::atoi(str.c_str()) <= 255) {
				tmp.push_back(str);
				dfs(ans, s, tmp, "", i + 1);
				tmp.pop_back();
			} else if (std::atoi(str.c_str()) > 255) {
				return;
			}
		}
	}
};
