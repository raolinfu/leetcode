#include<vector>
#include<iostream>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	vector<vector<string>>  res;
	unordered_map<string, int> mp;
	int cnt = 0;
	for(auto str: strs){
		string tmp = str;
		sort(tmp.begin(), tmp.end()); 
		if(mp.find(tmp) == mp.end()){
			mp[tmp] = cnt;
			res.push_back(vector<string>{str});
			cnt++;
		}else{
			int idx = mp[tmp];
			res[idx].push_back(str);
		}
	}

	return res;
}

int main(){
	vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> res = groupAnagrams(strs);
	for(auto strs: res){
		for(auto str: strs){
			cout<< str<<"\t";
		}
		cout<< endl;
	}
	return 0;
}
