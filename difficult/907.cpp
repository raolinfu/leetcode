#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
/* 
 * 超时
 * dp[i][j] i...j的最小值min(dp[i][j - 1], arr[j])
 * */
int sumSubarrayMins(vector<int>& arr) {
	int res = 0;
	int len = arr.size();
	vector<vector<int>> dp(len, vector<int>(len));
	for(int i = 0; i < len; i++){
		for(int j = i; j < len; j++){
			if(i == j){
				dp[i][j] = arr[i];
				continue;
			}
			dp[i][j] = min(arr[j], dp[i][j - 1]);
		}
	}
	for(int i = 0; i < len; i++){
		for(int j = 0; j < len; j++){
				res += dp[i][j];
		}
	}

	return res % ((int)pow(10, 9) + 7);
	return res;
}

int main(){
	// vector<int> arr = {3,1,2,4};
	vector<int> arr = {11,81,94,43,3};
	int res = sumSubarrayMins(arr);
	cout<< res<< endl;
	return 0;
}
