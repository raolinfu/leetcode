#include<string>
#include<utility>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

bool comp(const pair<int, int> a, const pair<int, int> b){
	if(a.first < b.first)
		return true;
	else if(a.first == b.first)
		return a.second < b.second;
	else
		return false;
}

pair<int, int> process(string &s);
int findMaxForm(vector<string>& strs, int m, int n) {
	int res = 0;
	int len = strs.size();
	int left = 0;
	int right = 0;
	int zero_num = 0;
	int one_num = 0;
	vector<pair<int, int>> dp(len);
	for(int i = 0; i < len; i ++){
		dp[i] = process(strs[i]);
	}
	sort(dp.begin(), dp.end(), comp);
	for(int i = 0; i < len; i ++){
		cout << dp[i].first<< "\t"<< dp[i].second<< endl;
	}
	cout<< "----------"<< endl;
	while(left <= right && right < len){
		if(zero_num <= m){
			if(one_num <= n){
				res = max(res, right - left + 1);
				cout<< left<< "\t"<< right<< endl;
			}
			right++;
			if(right < len){
				zero_num += dp[right].first;
				one_num += dp[right].second;
			}
		}else if(zero_num > m){
			zero_num -= dp[left].first;
			one_num -= dp[left].second;
			left++;
		}
	}

	return res;
}

pair<int, int> process(string &s){
	int zero = 0;
	int one = 0;
	for(char ch: s){
		if(ch == '0')
			zero++;
		else
			one++;
	}
	return pair<int, int>(zero, one);
}
int main(){
	vector<string>strs = {"10", "0001", "111001", "1", "0"};
	int m = 5;
	int n = 3;
	int res = findMaxForm(strs, m, n);
	cout<< res<< endl;
	return 0;
}
