#include<string>
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
/*
 *去除重复字母
 * */
string removeDuplicateLetters(string s) {
	unordered_set<char> set;
	string res;
	for(int i = 0; i < s.length(); i++){
		if(set.find(s[i]) == set.end())
		{
			set.insert(s[i]);
			res += s[i];
			continue;
		}

		int pos = res.find(s[i]);
		if(pos + 1 < res.length()  && res[pos] > res[pos + 1] ){
			res.erase(pos, 1);
			res += s[i];
		}
	}
	return res;
}

int main(){
	string s = "cdabc";
	string res = removeDuplicateLetters(s);	
	cout << res << endl;

	return 0;
}

