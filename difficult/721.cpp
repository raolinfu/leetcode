#include<string>
#include<iostream>
#include<set>
#include<algorithm>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

void dfs(vector<vector<string>>& accounts, vector<vector<int>> &graph, set<string>& priorQ, vector<bool>& visited, int i);
vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	vector<vector<string>> res;
	unordered_map<string, int> map;
	int len = accounts.size();
	vector<vector<int>> graph(len, vector<int>());
	vector<bool> visited(len, false);
	set<string> priorQ;
	for(int i = 0; i < len; i++){
		for(int j = 1; j < accounts[i].size(); j++){
			string email = accounts[i][j];
			// 构建边
			if(map.count(email)){
				graph[map[email]].push_back(i);
			}else{
				map[accounts[i][j]] = i;
			}
		}
	}

	// 遍历图
	for(int i = 0; i < len; i++){
		priorQ.clear();
		if(visited[i])
			continue;
		dfs(accounts, graph, priorQ, visited, i);
		vector<string> tmp = {accounts[i][0]};
		for(auto iter = priorQ.begin(); iter != priorQ.end(); iter++)
			tmp.push_back(*iter);

		res.push_back(tmp);
	}

	return res;
}

void dfs(vector<vector<string>>& accounts, vector<vector<int>> &graph, set<string>& priorQ, vector<bool>& visited, int i){
	if(visited[i])
		return;
	for(int j = 1; j < accounts[i].size(); j++)
		priorQ.insert(accounts[i][j]);
	visited[i] = true;

	for(auto vec: graph){
		for(auto ele: vec){
			if(visited[ele]){
				continue;
			}
			for(int j = 1; j < accounts[ele].size(); j++){
				visited[ele] = true;
				dfs(accounts, graph, priorQ, visited, j);
			}
		}
	}
}


int main(){
	vector<vector<string>>accounts = {{"John", "johnsmith@mail.com", "john00@mail.com"}, {"John", "johnnybravo@mail.com"}, {"John", "johnsmith@mail.com", "john_newyork@mail.com"}, {"Mary", "mary@mail.com"}};
	vector<vector<string>> res = accountsMerge(accounts);
	for(auto accounts: res){
		for(auto account: accounts){
			cout<< account<< " ";
		}
		cout<< endl;
	}

	return 0;
}
