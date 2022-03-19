#include <vector>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
		vector<vector<int>> graphs(n, vector<int>());
		vector<bool> visited(n, false);
		vector<bool> color(n, false);
		for (int i = 0; i < dislikes.size(); i++) {
			int n0 = dislikes[i][0];
			int n1 = dislikes[i][1];
			graphs[n0 - 1].push_back(n1 - 1);
			graphs[n1 - 1].push_back(n0 - 1);
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				traveler(graphs, visited, color, i);
				if (!ok)
					return false;
			}
		}

		return true;
    }

	void traveler(vector<vector<int>>& graphs, vector<bool>& visited, vector<bool>& color, int i) {
		visited[i] = true;
		for (auto node: graphs[i]) {
			if (!visited[node]) {
				color[node] = !color[i];
				traveler(graphs, visited, color, node);
			} else {
				if (color[node] == color[i]) {
					ok = false;
					return;
				}
			}
		}
	}
private:
	bool ok = true;
};
