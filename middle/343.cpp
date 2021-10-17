#include<iostream>
#include<vector>
using namespace std;
/*
 *整数拆分 dp[i]是拆分的最大成绩 dp[n] = max(dp[i] + dp[n - i])
 *当数分割后比原来数要大 那就分割
 * */
int integerBreak(int n) {
	vector<int> dp(n + 1, 0);
	dp[1] = 1;
	dp[2] = 1;
	for(int i = 3; i <= n; i++){
		for(int j = 1; j < i; j++){
			dp[i] = max(dp[i], max(dp[j] * (i - j), j * (i -j)));
		}

	}

	return dp[n];
}

int main(){
	int n = 5;
	int res = integerBreak(n);
	cout<< res<< endl;
	return 0;
}
