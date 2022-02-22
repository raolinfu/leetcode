#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
class Solution {
public:
    int longestSubsequence(vector<int> &arr, int difference) {
        int ans = 0;
        unordered_map<int, int> dp;
        for (int v: arr) {
            dp[v] = dp[v - difference] + 1;
            ans = max(ans, dp[v]);
        }
        return ans;
    }
};
int main(){
	return 0;
}
