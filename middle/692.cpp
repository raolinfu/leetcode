#include<string>
#include<utility>
#include<vector>
#include<unordered_map>
#include<iostream>
#include<queue>
using namespace std;

struct comp{
	bool operator()(const pair<string, int> a, const pair<string, int> b){
		if(a.second < b.second)
			return true;
		else if(a.second == b.second)
			return a.first > b.first;
		return false;
	}
};

vector<string> topKFrequent(vector<string>& words, int k) {
	vector<string> res;
	unordered_map<string, int> mp;
	for(auto word: words){
		mp[word]++;
	}
	priority_queue<pair<string, int>, vector<pair<string, int>>, comp> q;
	for(auto iter = mp.begin(); iter != mp.end(); iter++){
		q.push(*iter);
	}
	for(int i = 0; i < k; i++){
		if(!q.empty()){
			res.push_back(q.top().first);
			q.pop();
		}
	}

	return res;
}

int main(){
	vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
	int k = 2;
	/* vector<string> words = {"the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"};
	 * int k = 4; */
	vector<string> res = topKFrequent(words, k);
	for(auto s: res){
		cout<< s<< endl;
	}
	return 0;
}
