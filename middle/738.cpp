#include<string>
#include<utility>
#include<iostream>
using namespace std;

/* 
 * 1 单调递增 返回原数
 * 2 单调递减
 * 3 先减后增 与2情况一样
 * 4 先增后减
 *
 * */
pair<int, int> process(string &s);
int monotoneIncreasingDigits(int n) {
	int res;
	string str;
	// 多余 不需要
	/* if(n % 10 == 0 && n != 0)
	 *     return n - 1; */
	string s = to_string(n);	
	pair<int, int> p = process(s);
	cout<< s[p.second] - 1<< endl;
	if(p.first == 1)
		return n;
	else{
		str = s.substr(0, p.second);
		str.push_back(s[p.second] - 1);
		str += string(s.length() - p.second - 1, '9');
	}
	
	return stoi(str);
}

pair<int, int> process(string &s){
	if(s.length() == 1)
		return make_pair(1, 0);
	char pre = s[0];
	bool is_accend = true;
	int idx = 0;
	for(int i = 1; i < s.length(); i++){
		if(s[i] < pre){
			is_accend = false;
			break;
		}
		if(s[i] > pre)
			idx = i;
		pre = s[i];
	}
	// 单调递增
	if(is_accend)
		return make_pair(1, 0);
	else{
	// 有减的情况 返回减的位置
		return make_pair(2, idx);
	}
}

int main(){
	// int n = 12231;
	// int n = 12341;
	int n = 100;
	// int n = 110;
	int res = monotoneIncreasingDigits(n);
	cout<< res<< endl;
	return 0;
}
