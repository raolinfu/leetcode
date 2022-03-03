#include<vector>
#include<queue>
#include<unordered_map>
#include<iostream>
using namespace std;
struct cmp
{
    //重载 () 运算符
    bool operator()(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int> ans;
		unordered_map<int, int> mp;
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
		for(auto n: nums){
			mp[n]++;
		}
		for(auto p: mp){
			q.push(p);
		}
		for(int i = 0; i < k; i++){
			ans.push_back(q.top().first);
			q.pop();
		}

		return ans;
    }
};
