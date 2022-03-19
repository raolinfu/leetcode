#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		if (root == nullptr)
			return {};
		vector<vector<int>> ans;
		queue<TreeNode*> q;
		bool from_left = true;
		q.push(root);
		while (!q.empty()) {
			int len = q.size();
			vector<int> tmp;
			for (int i = 0; i < len; i++) {
				TreeNode* cur = q.front();
				tmp.push_back(cur->val);
				if (cur->left)
					q.push(cur->left);
				if (cur->right)
					q.push(cur->right);
				q.pop();
			}
			if (from_left) {
				ans.push_back(tmp);
			} else {
				reverse(tmp.begin(), tmp.end());
				ans.push_back(tmp);
			}
			from_left = !from_left;
		}

		return ans;
    }
};
