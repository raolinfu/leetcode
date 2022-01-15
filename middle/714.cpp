#include<vector>
#include<iostream>
using namespace std;
/* 
 *	dp[i]表示到第i天的最到利润
 * */
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
		int n = prices.size();
		vector<int> dp(n, 0);
		for(int i = 1; i < n; i++){
			dp[i] = dp[i - 1];
			for(int j = 0; j < i; j++){
				if(prices[i] > prices[j] + fee){
					dp[i] = max(dp[i], dp[j] + prices[i] - prices[j] - fee);
				}
			}
		}

		return dp[n - 1];
    }
/* 
 *	dp[i][0] 表示第i天手里没有股票的最大利润
 *	dp[i][1] 表示第i天手里有股票的最大利润
 * */
	int maxProfit1(vector<int>& prices, int fee) {
			int n = prices.size();
			vector<vector<int>> dp(n, vector<int>(2));
			dp[0][0] = 0, dp[0][1] = -prices[0];
			for (int i = 1; i < n; ++i) {
				dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
				dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
			}
			return dp[n - 1][0];
		}

	};
int main(){
	vector<int>prices = {1, 3, 2, 8, 4, 9};
	int fee = 2;
	Solution solution;
	int ans = solution.maxProfit(prices, fee);
	cout<< ans<< endl;
	return 0;
}
