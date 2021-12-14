#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<string>
#include<iostream>
using namespace std;

vector<string> getFolderNames(vector<string>& names) {
	vector<string> res;
	unordered_map<string, int> mp;
	unordered_set<string> set;
	for(auto name: names){
		// 如果name从未出现过 直接加进去
		if(!set.count(name))
		{
			set.insert(name);
			mp.insert({name, 0});
			res.push_back(name);
		}
	}

	return res;
}

int main(){

	return 0;
}
