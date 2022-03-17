#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
		int ans = 0;
		int n = costs.size();
		priority_queue<pair<int, int>> q;
		for (int i = 0; i < costs.size(); i++) {
			q.push({costs[i][0] - costs[i][1], i});
		}
		int i = 0;
		while (!q.empty()) {
			auto p = q.top();
			if (i < n / 2) {
				i++;
				ans += costs[p.second][1];
			} else if (i == n / 2) {
				ans += costs[p.second][0];
			}

			q.pop();
		}

		return ans;

    }
};
