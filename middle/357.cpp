#include<iostream>
#include<vector>
using namespace std;
/* 
 * dp[n]表示第一位非零的总的不同数字个数 dp[n] = 9 * A10 (n - 1)
 * */
int countNumbersWithUniqueDigits(int n) {
	int res = 0;
	if(n == 1 )
		return 10;
	else if(n > 10 || n < 1)
		return 0;
	
	vector<int> dp(n + 1, 9);
	dp[1] = 10;
	dp[2] = 81;
	for(int i = 3; i <= n; i++){
		for(int j = 0; j < i - 1; j++)
			dp[i] *= (9 - j); 
	}

	for(int i = 1; i <=n; i++){
		res += dp[i];
	}

	return res;
}

int main(){
	// int n = 3;
	int n = 4;
	int res = countNumbersWithUniqueDigits(n);
	cout<< res<< endl;
	return 0;
}
