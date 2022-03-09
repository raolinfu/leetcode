#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
class Solution {
public:
	vector<int> rearrangeBarcodes(vector<int>& barcodes) {
		vector<int> ans;
		unordered_map<int, int> mp;
		priority_queue<pair<int, int>> q;
		for(auto n: barcodes)
			mp[n]++;
		for(auto iter: mp)
			q.push({iter.second, iter.first});
		while(q.size() > 1){
			auto pr1 = q.top();
			q.pop();
			auto pr2 = q.top();
			q.pop();
			int diff = pr1.first - pr2.first;
			int n1 = pr1.second;
			int n2 = pr2.second;
			if(diff > 0)
				q.push({diff, n1});
			for(int i = 0; i < pr2.first; i++){
				ans.push_back(n1);
				ans.push_back(n2);
			}
		}

		if(q.size() > 0 && q.top().first == 1){
			ans.push_back(q.top().second);
			return ans;
		}else if(q.size() > 0){
			int n = q.top().second;
			int l = q.top().first;
			ans.push_back(n);
			l--;

			vector<int> tmp;	
			int i = 0;
			while(i < l){
				tmp.push_back(n);
				tmp.push_back(ans[i]);
				i++;
			}
			while(i < ans.size()){
				tmp.push_back(ans[i]);
				i++;
			}
			return tmp;
		}

		return ans;
	}

};
int main(){
	Solution sol;
	vector<int>barcodes = {1,1,1,2,2,2};
	auto ans = sol.rearrangeBarcodes(barcodes);
	for(auto n: ans)
		cout<< n<< " ";
	cout<< endl;
	/* priority_queue<int> q;
	 * q.push(1);
	 * q.push(12);
	 * q.push(2);
	 * while(!q.empty()){
	 *     cout<< q.top()<< endl;
	 *     q.pop();
	 * } */

	return 0;
}



