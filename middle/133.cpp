#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

/* 
 * 1 遍历原图 未遍历的点放在队列 节点个数
 * 2 遍历原图 组建新图
 * */
class Solution {
public:
    Node* cloneGraph(Node* node) {
		queue<Node*> q;
		unordered_set<Node*> set;
		unordered_map<int, Node*> mp;
		int cnt = 0;
		if (node == nullptr)
			return node;
		q.push(node);
		set.insert(node);
		while (!q.empty()) {
			auto cur = q.front();
			cnt = max(cnt, cur->val);
			for (auto n: cur->neighbors) {
				if (set.count(n)) {
					continue;
				}
				set.insert(n);
				q.push(n);
			}
			q.pop();
		}

		for (int i = 1; i <= cnt; i++) {
			mp.insert({i, new Node(i)});
		}

		set.clear();
		q.push(node);
		set.insert(node);
		while (!q.empty()) {
			Node* cur = q.front();
			Node* new_node = mp[cur->val];
			for (auto n: cur->neighbors) {
				new_node->neighbors.push_back(mp[n->val]);
				if (set.count(n)) {
					continue;
				}
				q.push(n);
				set.insert(n);
			}
			q.pop();
		}

		return mp[node->val];
    }
};
