#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

class Solution {
private:
	unordered_map<char, int> map;
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		int ans = 0;
		int cnt = 0;
		int i = 0;
		process(strs, ans, i, cnt, m, n);
		return ans;
    }

	void process(vector<string>& strs, int& ans, int i, int cnt, int m, int n){
		if(i == strs.size() || m < 0 || n < 0)
			return;
		map.clear();
		for(auto ch: strs[i])
			map[ch]++;
		if(map['0'] <= m && map['1'] <= n){
			ans = max(ans, cnt + 1);
			process(strs, ans, i + 1, cnt + 1, m - map['0'], n - map['1']);
		}
		process(strs, ans, i + 1, cnt, m, n);
	}

	vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm1(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= length; i++) {
            vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        return dp[length][m][n];
    }

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/ones-and-zeroes/solution/yi-he-ling-by-leetcode-solution-u2z2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
};
int main(){
	/* vector<string>strs = {"10", "0001", "111001", "1", "0"};
	 * int m = 5;
	 * int n = 3; */
	vector<string>strs = {"10", "0", "1"};
	int m = 1;
	int n = 1;
	Solution solution;
	int ans = solution.findMaxForm(strs, m, n);
	cout<< ans<< endl;
	return 0;
}
