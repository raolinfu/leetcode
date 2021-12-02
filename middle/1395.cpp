#include<vector>
#include<iostream>
using namespace std;

// 时间复杂读O(n*n)的算法
// 以rating[i]结尾的三元组
int numTeams(vector<int>& rating) {
	int ans = 0;
	int len = rating.size();
	vector<int> low(len, 0);
	vector<int> high(len, 0);
	for(int i = 0; i < len; i++){
		for(int j = 0; j <= i; j++){
			if(rating[i] > rating[j]){
				ans += high[j];
				high[i]++;
			}else if(rating[i] < rating[j]){
				ans += low[j];
				low[i]++;
			}
		}
	}

	return ans;
}

// 时间复杂读O(n*n)的算法 rating[i] 
// 左边比他大的和右边比他小的
// 左边比他小的和右边比他大的
int numTeams1(vector<int>& rating) {
	int ans = 0;
	int len = rating.size();
	vector<int> dp(len);

	return ans;
}
int main(){
	// vector<int>rating = {2,5,3,4,1};
	// vector<int>rating = {2,1,3};
	vector<int>rating = {1,2,3,4};
	int ans = numTeams(rating);
	cout<< ans<< endl;

	return 0;
}
