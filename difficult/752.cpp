#include<string>
#include<climits>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
#include<vector>
using namespace std;

int dfs(string &target, unordered_map<string, int>& mp, unordered_set<string>& s, string& str, int cnt);
int openLock(vector<string>& deadends, string target) {
	int res = INT_MAX;
	unordered_set<string> s(deadends.begin(), deadends.end());
	unordered_map<string, int> mp;
	string str = "0000";
	res = dfs(target, mp, s, str, 0);
	cout<< mp["0000"]<< endl;
	return res;
}

int dfs(string &target, unordered_map<string, int>& mp, unordered_set<string>& s, string& str, int cnt){
	if(str == target)
		return cnt;
	if(mp.count(str))
		return mp[str];

	mp[str] = INT_MAX;
	if(s.count(str))
		return mp[str];

	for(int i = 0; i < 4; i++){
		for(int j = 0; j <= 9; j++){
			char ch = '0' + j;
			char tmp = str[i];
			if(str[i] != ch){
				str[i] = ch;
				int cand = dfs(target, mp, s, str, cnt + 1);
				mp[str] = min(mp[str], cand);
				str[i] = tmp;
			}
		}
	}

	return mp[str];
}

int main(){

	vector<string>deadends = {"0201","0101","0102","1212","2002"};
	string target = "0202";
	int res = openLock(deadends, target);
	cout<< res<< endl;
	return 0;
}
