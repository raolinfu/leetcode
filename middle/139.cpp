#include<vector>
#include<string>
using namespace std;

// 暴力搜索法 超时
bool process(string &s, vector<string>& wordDict, int b);
bool wordBreak(string s, vector<string>& wordDict) {
	if(process(s, wordDict, 0))
		return true;

	return false;
}

bool process(string &s, vector<string>& wordDict, int b){
	if(b == s.length())
		return true;
	for(int i = 0; i < wordDict.size(); i++){
		if(wordDict[i].length() > s.length() - b)
			continue;
		else if(wordDict[i] == s.substr(b, wordDict[i].size())){
			if(process(s, wordDict, b + wordDict[i].size())){
				return true;
			}else{
				continue;	
			};
		}
	}

	return false;
}

int main(){
	string s = "applepenapple";
	vector<string> wordDict = {"apple", "pen"};
	int res = wordBreak(s, wordDict);
	return 0;
}
