#include<vector>
#include<climits>
#include<iostream>
/*
 *零钱兑换
 * */
using namespace std;

void process(int rest, vector<int> &coins, int &res, int &cur);
/*
 *动态规划
 * dp[i]表示钱为i时的最少找钱数
 * dp[j] j - i 在coins里 则dp[j] = min dp[j - coins[i]]
 * 	前提是dp[j - coins[i]]能找开
 * */
int coinChange1(vector<int>& coins, int amount) { 
	if(amount == 0)
		return 0;
	vector<int> dp(amount + 1, INT_MAX);
	for(int i = 0; i < amount + 1; i++){
		for(int j = 0; j < coins.size(); j++){
			if(coins[j] == i)
			{
				dp[i] = 1;
				continue;
			}

			if(i - coins[j] > 0 && dp[i - coins[j]] != INT_MAX){
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
		}
	}
	return dp[amount] == INT_MAX? -1: dp[amount];
}

int coinChange(vector<int>& coins, int amount) {
	int res = INT_MAX;
	int cur = 0;
	process(amount, coins, res, cur);
	return res;
}
/*
 *回溯加剪枝的做法
 * */
void process(int rest, vector<int> &coins, int &res, int &cur){
	if(cur > res)
		return;
	if(rest == 0){	
		res = cur;
		return;
	}
	for(int coin: coins){
		if(rest < coin)
			return;
		process(rest - coin, coins, res, ++cur);
		--cur;
	}
}

int main(){
 	vector<int> coins = {1, 2, 5};
	int amount = 11;
	int res = coinChange(coins, amount);
	cout<< res<< endl;

	res = coinChange1(coins, amount);
	cout<< res<< endl;
	return 0;
}
