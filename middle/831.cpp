#include <cctype>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string maskPII(string s) {
		string ans;
		int idx = s.find('@');
		if(idx == s.npos){
			return processPhone(s);
		}
		else{
			return processEmail(s, idx);
		}

    }
	string processEmail(string& s, int idx){
		for(int i = 0; i < s.length(); i++){
			if(std::isalpha(s[i]) && std::isupper(s[i])){
				s[i] = std::tolower(s[i]);
			}
		}
		string ans;
		ans += s[0];
		ans.append("*****");
		ans += s[idx - 1];
		ans.append(s.substr(idx));

		return ans;
	}

	string processPhone(string& s){
		int numCnt = 0;
		string ans;
		string tmp;
		for(auto ch: s){
			if(std::isdigit(ch)){
				numCnt++;
				tmp += ch;
			}
		}
		if(numCnt == 10){
			ans += "***-***-";
			ans += tmp.substr(tmp.length() - 4);
		}else if(numCnt == 11){
			ans += "+*-***-***-";
			ans += tmp.substr(tmp.length() - 4);
		}
		else if(numCnt == 12){
			ans += "+**-***-***-";
			ans += tmp.substr(tmp.length() - 4);
		}
		else if(numCnt == 13){
			ans += "+***-***-***-";
			ans += tmp.substr(tmp.length() - 4);
		}

		return ans;
	}

};
int main(){
	Solution sol;
	// string s = "LeetCode@LeetCode.com";
	string s = "86-(10)12345678";
	cout<< sol.maskPII(s)<< endl;


	return 0;
}
