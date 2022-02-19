#include<unordered_map>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string frequencySort(string s) {
		string ans;
		unordered_map<char, int> map;
		int maxNum = 0;
		for(auto ch: s){
			maxNum = max(maxNum, ++map[ch]);
		}

		vector<string> strs(maxNum + 1);
		for(auto [k, v]: map){
			strs[v] += k;
		}

		for(int i = maxNum; i >= 0; i--){
			for(auto ch: strs[i]){
				ans.append(string(i, ch));
			}
		}

		return ans;
    }
};
int main(){
	Solution s;
	string str = "tree";
	cout<< s.frequencySort(str)<< endl;
	return 0;
}
