#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
		vector<vector<int>> ans;
		priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> q;
		for (int i = 0; i < points.size(); i++) {
			int x = points[i][0];
			int y = points[i][1];
			q.push({x * x + y * y, i});
		}
		while (!q.empty() && k > 0) {
			auto [_, i] = q.top();
			ans.push_back(points[i]);
			q.pop();
			k--;
		}

		return ans;
    }
};
