#include<vector>
#include<algorithm>
#include<climits>
#include<iostream>
#include<queue>
using namespace std;

struct Comp{
	bool operator()(const pair<int, int>& a, const pair<int, int>& b){
		return a.first > b.first;
	}
};
int networkDelayTime(vector<vector<int>>& times, int n, int k) {
	 const int inf = INT_MAX / 2;
	vector<vector<pair<int, int>>> g(n); for (auto &t : times) {
		int x = t[0] - 1, y = t[1] - 1;
		g[x].emplace_back(y, t[2]);
	}

	vector<int> dist(n, inf);
	dist[k - 1] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
	q.emplace(0, k - 1);
	while (!q.empty()) {
		auto p = q.top();
		q.pop();
		int time = p.first, x = p.second;
		// {1, 10} {1, 8}的结果 只管往queue里放 之前放到不管
		if (dist[x] < time) {
			continue;
		}
		for (auto &e : g[x]) {
			int y = e.first, d = dist[x] + e.second;
			if (d < dist[y]) {
				dist[y] = d;
				q.emplace(d, y);
			}
		}
	}

	int ans = *max_element(dist.begin(), dist.end());
	return ans == inf ? -1 : ans;

}

int main(){

	return 0;
}
