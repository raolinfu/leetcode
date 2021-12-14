#include<iostream>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	vector<vector<string>> res;

	return res;
}

void process(vector<vector<string>> &res, string &endWord, vector<string> &cur,unordered_set<string> &set,string cmpStr){
	if(cmpStr == endWord)
		res.push_back(cur);
	for(int i = 0; i < cmpStr.length(); i++){
		if(set.k)
	}

}
