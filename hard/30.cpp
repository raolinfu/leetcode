#include<vector>
#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

/* 
 * 用hash 
 * */
bool isValid(string &s, unordered_map<string, int> mp, int idx, int len, int size);
vector<int> findSubstring(string s, vector<string>& words) {
	vector<int> res;
	unordered_map<string, int> mp;
	for(int i = 0; i < words.size(); i++){
		if(mp.find(words[i]) == mp.end())
			mp[words[i]] = 1;
		else
			mp[words[i]]++;
	}
	for(int i = 0; i < s.length(); i++){
		if(isValid(s,  mp, i, words[0].length(), words.size())){
			res.push_back(i);
		}
	}
	return res;
}
/* 
 *	还是超时 将函数改成inline
 * */
bool isValid(string &s, unordered_map<string, int> mp, int idx, int len, int size){
	if(s.length() - idx < len * size)
		return false;

	for(int i = 0; i < size; i++){
		string sub = s.substr(idx + len * i, len);
		if(mp.find(sub) == mp.end()){
			return false;
		}else if(mp[sub] <= 0){
			return false;
		}
		mp[sub]--;
	}		
	return true;
}

/* 
 *	递归解法 时间复杂读O(n*2^k) k为words的size n为s长度 时间复杂读太大
 * */
int main(){
	/* string s = "barfoothefoobarman";
	 * vector<string> words = {"foo","bar"}; */
	string s = "barfoofoobarthefoobarman";
	vector<string> words = {"bar","foo","the"};
	vector<int> res = findSubstring(s, words);
	for(int i = 0; i < res.size(); i++)
		cout << res[i]<< endl;
	return 0;
}
