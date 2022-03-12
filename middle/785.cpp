#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int> nodes(n, 0);
		for(int i = 0; i < n; i++){
			if(nodes[i] == 0){
				if(!isValid(graph, nodes, i)){
					return false;
				}
			}
		}

		return true;
    }

	bool isValid(vector<vector<int>>& graph, vector<int>& nodes, int i){
		queue<int> q;
		q.push(i);
		nodes[i] = 1;
		while(!q.empty()){
			int top = q.front();
			int curCol = nodes[top];
			int newCol = curCol == 1? 2: 1;
			for(auto n: graph[top]){
				// 和相邻点颜色相同
				if(nodes[n] == curCol){
					return false;
				}
				// 只有相邻的还没上色的放入q
				else if(nodes[n] == 0){
					nodes[n] = newCol;
					q.push(n);
				}
			}
			q.pop();
		}

		return true;
	}
};
