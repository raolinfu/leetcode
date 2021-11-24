#include<iostream>
#include<vector>
#include<string>
using namespace std;
/* 
 * 重点是记录每一位后面的大于该为最早出现的位置
 * */
int maximumSwap(int num) {
	string s = to_string(num);
	int len = s.length();
	vector<int> dp(len);
	if(len == 1)
		return num;
	dp[len - 1] = len - 1;
	char maxChar = s[len - 1];
	char idx = len - 1;
	for(int i = len - 1; i >= 0; i--){
		if(maxChar >= s[i]){
			dp[i] = idx;
		}else{
			maxChar = s[i];
			idx = i;
			dp[i] = idx;
		}
	}
	for(int i = 0; i < len; i++){
		cout<< dp[i]<< "\t";
	}
	cout<< endl;
	for(int i = 0; i < len; i++){
		if(s[i] != s[dp[i]]){
			swap(s[i], s[dp[i]]);
			return stoi(s);
		}
	}
	
	return num;
}

int main(){
	string s = "abc";
	std::swap(s[1], s[2]);
	cout<< s<< endl;
	int num = 2736;
	// int num = 2763;
	int res = maximumSwap(num);
	cout<< res<< endl;
	return 0;
}
