#include<vector>
#include<algorithm>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if(root == nullptr)
			return ans;
		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			int len = q.size();
			vector<int> tmp;
			for(int i = 0; i < len; i++){
				auto f = q.front();
				tmp.push_back(f->val);
				if(f->left)
					q.push(f->left);
				if(f->right)
					q.push(f->right);
				q.pop();
			}

			ans.push_back(tmp);
		}
		std::reverse(ans.begin(), ans.end());

		return ans;
    }
};
