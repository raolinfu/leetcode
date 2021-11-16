#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

string customSortString(string order, string s) {
	string res;
	unordered_map<char, int> mp;
	for(int i = 0; i < order.length(); i++){
		if(!mp.count(order[i])){
			mp[order[i]] = 0;	
		}
	}
	for(int i = 0; i < s.length(); i++){
		if(!mp.count(s[i]))
			res.push_back(s[i]);
		else{
			mp[s[i]]++;
		}
	}

	for(int i = 0; i < order.length(); i++){
		if(mp.count(order[i]) && mp[order[i]]){
			res += string(mp[order[i]], order[i]);
		}
	}
	return res;
}

int main(){
	string s = "cba";
	string t = "abcd";
	string res = customSortString(s, t);
	cout<< res<< endl;
	return 0;
}
