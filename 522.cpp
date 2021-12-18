#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<iostream>
using namespace std;

void process(unordered_set<string>& set, string& str, string s, int i);
int findLUSlength(vector<string>& strs) {
	int ans = 0;
	unordered_map<string, int> map;
	vector<unordered_set<string>> records(strs.size(), unordered_set<string>());
	for(int i = 0; i < strs.size(); i++){
		string s;
		process(records[i], strs[i], s, 0);
	}

	for(int i = 0; i < strs.size(); i++){
		for(auto iter: records[i]){
			map[iter]++;
		}
	}

	for(auto iter: map){
		if(iter.second == 1)
			ans = max(ans, (int)iter.first.length());
	}

	return ans == 0? -1: ans;
}

void process(unordered_set<string>& set, string& str, string s, int i){
	if(i == str.length()){
		set.insert(s);
		return;
	}
	process(set, str, s, i + 1);
	process(set, str, s + str[i], i + 1);
}

int main(){
	// vector<string> strs = {"aba", "cdc", "eae"};
	vector<string> strs = {"aaa", "aaa", "aa"};
	int ans = findLUSlength(strs);
	cout<< ans<< endl;
	
	return 0;
}
