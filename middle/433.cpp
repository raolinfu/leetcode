#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <vector>
using namespace std;
class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
		int d = 0;
		unordered_set<string> valids(bank.begin(), bank.end());
		unordered_set<string> visited;
		unordered_map<char, vector<char>> mp {{'A', {'C', 'G', 'T'}},
											{'C', {'A', 'G', 'T'}},
											{'T', {'C', 'G', 'A'}},
											{'G', {'C', 'A', 'T'}}};
		queue<string> q;
		if (valids.count(end) == 0)
			return -1;
		q.push(start);
		while (!q.empty()) {
			int len = q.size();
			for (int i = 0; i < len; i++){
				string cur = q.front();
				if (cur == end)
					return d;
				for (int j = 0; j < cur.size(); j++) {
					char pre = cur[j];
					for (char ch: mp[cur[j]]) {
						cur[j] = ch;
						if (!visited.count(cur) && valids.count(cur)) {
							q.push(cur);
						}
					}
					cur[j] = pre;
				}
				visited.insert(cur);
				q.pop();
			}
			d++;
		}

		return -1;
    }
};
