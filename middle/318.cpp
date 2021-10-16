#include<string>
#include<cmath>
#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
/*
 *最大单词长度乘积
 * */
int maxProduct(vector<string>& words) {
	int res = 0;
	for(int i = 0; i < words.size(); i++){
		unordered_set<char> set(words[i].begin(), words[i].end());
		for(int j = i + 1; j < words.size(); j++){
			bool isValid = true;
			for(char ch: words[j]){
				if(set.find(ch) != set.end()){
					isValid = false;
					break;
				}
			}	
			if(isValid)
				res = max(res, (int)words[i].size() * (int)words[j].size());
		}
	}
	return res;
}

int main(){
	string s = "aabcbd";
	unordered_set<char> set(s.begin(), s.end());
	vector<string> words = {"abcw","baz","foo","bar","xtfn","abcdef"};
	int res = maxProduct(words);
	cout<< res<< endl;
	return 0;
}
