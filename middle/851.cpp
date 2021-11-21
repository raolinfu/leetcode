#include<vector>
#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
	// 钱不比i少的人
	unordered_map<int, vector<int>> mp;
	vector<int> ans(quiet.size());
	queue<int> q;
	for(int i = 0; i < quiet.size(); i++){
		mp[i] = vector<int>();
		ans[i] = i;
	}
	for(auto ele: richer){
		mp[ele[1]].push_back(ele[0]);
	}

	for(int i = 0; i < quiet.size(); i++){
		q.push(i);
		while(!q.empty()){
			int idx = q.front();
			auto vec = mp[idx];
			for(auto ele: vec){
				q.push(ele);
				if(quiet[ans[i]] > quiet[ele])
					ans[i] = ele;
			}
			q.pop();
		}

	}

	return ans;
}

int dfs(vector<vector<int>> &grah, vector<int>& ans, vector<int>& quiet, int i);
// 图的算法
vector<int> loudAndRich1(vector<vector<int>>& richer, vector<int>& quiet) {
	int len = quiet.size();
	vector<int> ans(len, -1);
	vector<vector<int>> grah(len, vector<int>());
	for(auto ele: richer){
		grah[ele[1]].push_back(ele[0]);
	}
	for(int i = 0; i < len; i++){
		dfs(grah, ans, quiet, i);
	}

	return ans;
}

int dfs(vector<vector<int>> &grah, vector<int>& ans, vector<int>& quiet, int i){
	// 
	if(ans[i] == -1){
		ans[i] = i;
		for(auto ele: grah[i]){
			int cand = dfs(grah, ans, quiet, ele);
			// 安静值更小 才更新 这里要注意 是用ans[i]去做比较
			if(quiet[ans[i]] > quiet[cand])
				ans[i] = cand;
		}
	}

	return ans[i];
}


int main(){
	/* vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
	 * vector<int> quiet = {3,2,5,4,6,1,7,0}; */
	vector<vector<int>> richer = {{0,2},{1,2}};
	vector<int> quiet = {0,1,2};
	// vector<int> ans = loudAndRich(richer, quiet);
	vector<int> ans = loudAndRich1(richer, quiet);
	for(auto ele: ans)
		cout<< ele<< " ";
	cout<< endl;
	ans = loudAndRich(richer, quiet);
	for(auto ele: ans)
		cout<< ele<< " ";
	cout<< endl;
	return 0;
}
