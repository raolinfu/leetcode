#include<vector>
#include<unordered_set>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
		string str;
		for(int i = 1; i<= 9; i++){
			str += '0' + i;
			dfs(str, n, k);
			str.pop_back();
		}

		return vector<int>(set.begin(), set.end());
    }
	void dfs(string& str, int& n, int& k){
		if(str.length() == n){
			set.insert(atoi(str.c_str()));
			// ans.push_back(atoi(str.c_str()));
			return;
		}
		char ch = str.back();
		if(ch - '0' + k <= 9){
			str.push_back(ch + k);
			dfs(str, n, k);
			str.pop_back();
		}

		if(ch - '0' - k >= 0){
			str.push_back(ch - k);
			dfs(str, n, k);
			str.pop_back();
		}
	}
private:
	unordered_set<int> set;
};
