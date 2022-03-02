#include <cctype>
#include <cwctype>
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
		vector<string> ans;
		string tmp;
		help(ans, s, tmp, 0);
		return ans;
    }
	void help(vector<string>& ans, string& s, string& tmp, int i){
		if(i == s.length()){
			ans.push_back(tmp);
			return;
		}
		char ch = s[i];
		if(!std::isalpha(ch)){
			tmp.push_back(ch);
			help(ans, s, tmp, i + 1);
			tmp.pop_back();
		}
		else{
			tmp.push_back(std::tolower(ch));
			help(ans, s, tmp, i + 1);
			tmp.pop_back();

			tmp.push_back(std::towupper(ch));
			help(ans, s, tmp, i + 1);
			tmp.pop_back();
		}
	}
};
int main(){
	Solution s;
	// string s1 = "a1b2";
	string s1 = "3z4";
	auto ans = s.letterCasePermutation(s1);
	for(auto ele: ans){
		cout<< ele<< endl;
	}

	return 0;
}
