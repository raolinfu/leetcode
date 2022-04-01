#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution1 {
private:
    // 记忆化搜索存储状态的数组
    // -1 表示 false，1 表示 true，0 表示未计算
    int memo[30][30][31];
    string s1, s2;

public:
    bool checkIfSimilar(int i1, int i2, int length) {
        unordered_map<int, int> freq;
        for (int i = i1; i < i1 + length; ++i) {
            ++freq[s1[i]];
        }
        for (int i = i2; i < i2 + length; ++i) {
            --freq[s2[i]];
        }
        if (any_of(freq.begin(), freq.end(), [](const auto& entry) {return entry.second != 0;})) {
            return false;
        }
        return true;
    }

    // 第一个字符串从 i1 开始，第二个字符串从 i2 开始，子串的长度为 length，是否和谐
    bool dfs(int i1, int i2, int length) {
        if (memo[i1][i2][length]) {
            return memo[i1][i2][length] == 1;
        }

        // 判断两个子串是否相等
        if (s1.substr(i1, length) == s2.substr(i2, length)) {
            memo[i1][i2][length] = 1;
            return true;
        }

        // 判断是否存在字符 c 在两个子串中出现的次数不同
        if (!checkIfSimilar(i1, i2, length)) {
            memo[i1][i2][length] = -1;
            return false;
        }
        
        // 枚举分割位置
        for (int i = 1; i < length; ++i) {
            // 不交换的情况
            if (dfs(i1, i2, i) && dfs(i1 + i, i2 + i, length - i)) {
                memo[i1][i2][length] = 1;
                return true;
            }
            // 交换的情况
            if (dfs(i1, i2 + length - i, i) && dfs(i1 + i, i2, length - i)) {
                memo[i1][i2][length] = 1;
                return true;
            }
        }

        memo[i1][i2][length] = -1;
        return false;
    }

    bool isScramble(string s1, string s2) {
        memset(memo, 0, sizeof(memo));
        this->s1 = s1;
        this->s2 = s2;
        return dfs(0, 0, s1.size());
    }
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
		if (!isValid(s1, s2))
			return false;
		vector<string> ans = dfs(s1, s2);
		for (auto str: ans) {
			if (str == s2)
				return true;
		}

		return false;
    }

	// 超时
	vector<string> dfs(string& str, string& tar) {
		vector<string> ans;
		int n = str.length();
		ans.push_back(str);

		for (int i = 1; i < n; i++) {
			string left = str.substr(0, i);
			string right = str.substr(i);
			string tar1 = tar.substr(0, i);
			string tar2 = tar.substr(n - i);

			string tar3 = tar.substr(i);
			string tar4 = tar.substr(0, n - i);

			if (isValid(left, tar1)) {
				vector<string> left_strs = dfs(left, tar1);
				vector<string> right_strs = dfs(right, tar3);
				for (auto str1: left_strs) {
					for (auto str2: right_strs) {
						ans.push_back(str1 + str2);
						ans.push_back(str2 + str1);
					}
				}
			}

			if (isValid(left, tar2)) {
				vector<string> left_strs = dfs(left, tar2);
				vector<string> right_strs = dfs(right, tar4);
				for (auto str1: left_strs) {
					for (auto str2: right_strs) {
						ans.push_back(str1 + str2);
						ans.push_back(str2 + str1);
					}
				}
			}
		}

		return ans;
	}

	bool isValid(string& str1, string& str2) {
		if (str1.length() != str2.length())
			return false;
		unordered_map<char, int> mp;
		for (auto ch: str1)
			mp[ch]++;
		for (auto ch: str2) {
			mp[ch]--;
			if (mp[ch] < 0)
				return false;
		}

		return true;
	}
};
int main() {
	vector<int> n{1, 2, 3};
	return 0;
}
