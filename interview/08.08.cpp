#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

void process(vector<string> &res, vector<bool> &used, string &s, string &cur, int idx);
vector<string> permutation(string S) {
	vector<string> res;
	vector<bool> used(S.size(), false);
	sort(S.begin(), S.end());
	string cur = "";
	process(res, used, S, cur, 0);

	return res;
}

void process(vector<string> &res, vector<bool> &used, string &s, string &cur, int idx){
	if(idx == s.length()){
		res.push_back(cur);
		return;
	}
	char pre = 0;
	for(int i = 0; i < s.length(); i++){
		if(!used[i] && s[i] != pre){
			pre = s[i];
			used[i] = true;
			cur.push_back(s[i]);
			process(res, used, s, cur, idx + 1);
			cur.pop_back();
			used[i] = false;
		}
	}
}

int main(){
	string S = "qqe";
	vector<string> res = permutation(S);
	for(auto s: res)
		cout<< s<< endl;
	return 0;
}
