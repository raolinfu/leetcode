#include<string>
#include<vector>
#include<unordered_map>
#include<iostream>
using namespace std;

vector<int> findAnagrams1(string s, string p) {
	vector<int> res;
	if(s.length() < p.length())
		return res;
	unordered_map<char, int> mp;
	for(char ch: p){
		mp[ch]++;
	}
	int n = p.length();
/* 
 *	如果是大于0,则缺,相应的n要减小.如果是小于或等于0,说明不缺了,则n是不变,但自身要变
 * */
	for(int i = 0; i < p.length(); i++){
		if(mp.find(s[i]) != mp.end()){
			if(mp[s[i]]){
				n--;
			}
			mp[s[i]]--;
			
		}
		if(n == 0)
			res.push_back(0);
	}
/* 
 *	mp[s[i]] < 0说明是富足的, n不能变. 大于0,说明是缺的.相应的n则要增加或减少
 *
 * */
	for(int i = 1, j = p.length(); j < s.length(); j++, i++){
		if(mp.find(s[i - 1]) != mp.end()){
			// 不要再使用count()了,对map来说,就是键存在即可
			if(mp[s[i - 1]] >= 0){
				n++;
			}
			mp[s[i - 1]]++;
			
		}
		if(mp.find(s[j]) != mp.end()){
			if(mp[s[j]]){
				n--;
			}
			mp[s[j]]--;
		}
		if(n == 0)
			res.push_back(i);
	}

	return res;
}
vector<int> findAnagrams(string s, string p) {
	vector<int> res;
	if(s.length() < p.length())
		return res;
	unordered_map<char, int> mp;
	for(char ch: p){
		mp[p[ch]]++;
	}
	for(int i = 0; i < s.length() - p.length(); i++){
		unordered_map<char, int> tmp = mp;
		int n = p.length();
		for(int step = 0; step < p.length(); step++){
			if(tmp.find(s[i + step]) != tmp.end() && tmp.count(s[i + step])){
				n--;
			}
		}
		if(n == 0)
			res.push_back(i);
	}

	return res;
}

int main(){
	/* string s = "cbaebabacd";
	 * string p = "abc"; */
	string s = "cabcaefabcab";
	string p = "abc";
	vector<int> res = findAnagrams1(s, p);

	for(int i: res){
		cout<< i<< endl;
	}

	return 0;
}
