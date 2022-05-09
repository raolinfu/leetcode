#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Solution {
	public:
		void sortMulNums(vector<vector<int>>& grid) {
			int n = grid.size();
			vector<int> next(n, 0);
			vector<int> ans;
			auto cmp = [&](const int a, const int b) {
				return grid[a][next[a]] > grid[b][next[b]];
			};
			std::priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
			for (int i = 0; i < n; i++)
				pq.emplace(i);

			while (!pq.empty()) {
				int row = pq.top();
				pq.pop();
				int min_num = grid[row][next[row]];
				ans.push_back(min_num);
				next[row]++;
				if (next[row] < grid[row].size()) {
					pq.emplace(row);
				}
			}

			for (int& i: ans)
				cout<< i<< "\t";
			cout<< endl;
		};
};

int main() {
	vector<vector<int>> grid{{1, 3, 8}, {0, 2, 6, 9}, {5, 11}};
	Solution sol;
	sol.sortMulNums(grid);
	return 0;
}
