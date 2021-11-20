#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;
/* 
 *	dp[i] 表示难度i里的最大收益
 *
 * */
int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
	unordered_map<int, int> mp;
	int maxDiff = 0;
	int res = 0;
	for(int i = 0; i < difficulty.size(); i++){
		if(mp.count(!difficulty[i]))
			mp.insert({difficulty[i], profit[i]});
		else
			mp[difficulty[i]] = max(mp[difficulty[i]], profit[i]);
		maxDiff = max(maxDiff, difficulty[i]);
	}
	vector<int> dp(maxDiff + 1, 0);
	for(int i = 1; i <= maxDiff; i++){
		dp[i] = dp[i - 1];
		if(mp.count(i)){
			dp[i] = max(dp[i], mp[i]);
		}
	}
	for(int i = 0; i < worker.size(); i++){
		if(worker[i] > maxDiff)
			res += dp[maxDiff];
		else
			res += dp[worker[i]];
	}
	return res;
}

int main(){
	vector<int>difficulty = {2,4,6,8,10};
	vector<int>profit = {10,20,30,40,50};
	vector<int>worker = {4,5,6,7};
	int res = maxProfitAssignment(difficulty, profit, worker);
	cout<< res<< endl;
	return 0;
}
