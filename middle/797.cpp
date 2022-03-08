#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> ans;
		vector<int> tmp{0};
		dfs(ans, graph, tmp, 0);

		return ans;
    }

	void dfs(vector<vector<int>>& ans, vector<vector<int>>& graph, vector<int>& tmp, int cur){
		if(cur == graph.size() - 1){
			ans.push_back(tmp);
			return;
		}
		for(auto n: graph[cur]){
			tmp.push_back(n);
			dfs(ans, graph, tmp, n);
			tmp.pop_back();
		}
	}
};
