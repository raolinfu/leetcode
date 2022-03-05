#include<vector>
#include<queue>
using namespace std;

class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
		vector<vector<int>> ans;
		if(root == nullptr)
			return ans;
		queue<Node*> q;
		q.push(root);
		while(!q.empty()){
			int len = q.size();
			vector<int> tmp;
			for(int i = 0; i < len; i++){
				Node* front = q.front();
				for(auto node: front->children)
					q.push(node);
				tmp.push_back(front->val);
				q.pop();
			}
			ans.push_back(tmp);
		}
        
		return ans;
    }
};
