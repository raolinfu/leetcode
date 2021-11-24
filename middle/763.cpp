#include<vector>
#include<utility>
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;

vector<int> partitionLabels(string s) {
	vector<int> res;
	unordered_map<char, pair<int, int>> mp;
	vector<pair<int, int>> p;
	for(int i = 0; i < s.length(); i++){
		if(!mp.count(s[i])){
			mp[s[i]] = make_pair(i, i);
		}else{
			mp[s[i]].second = i;
		}
	}
	for(auto iter = mp.begin(); iter != mp.end(); iter++){
		p.push_back(iter->second);
	}

	sort(p.begin(), p.end());
	pair<int, int> pre = p[0];
	for(int i = 1; i < p.size(); i++){
		if(p[i].first > pre.first && p[i].first < pre.second){
			pre.second = max(pre.second, p[i].second);
		}else{
			res.push_back(pre.second - pre.first + 1);
			pre = p[i];
		}
	}
	res.push_back(pre.second - pre.first + 1);

	return res;
}

int main(){
	/* vector<pair<int, int>> p;
	 * p.push_back(make_pair(3, 2));
	 * p.push_back(make_pair(2, 2));
	 * sort(p.begin(), p.end());
	 * unordered_map<char, pair<int, int>> mp;
	 * mp['a'] = make_pair(0, 0);
	 * cout<< mp['a'].first<< "\t"<< mp['a'].second<< endl;
	 * mp['a'].second = 9;
	 * cout<< mp['a'].first<< "\t"<< mp['a'].second<< endl; */
	// string S = "ababcbacadefegdehijhklij";
	string S = "caedbdedda";
	vector<int> res = partitionLabels(S);
	for(auto n: res){
		cout<< n<< "\t";
	}
	cout<< endl;
	return 0;
}
