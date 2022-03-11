#include<stack>
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
    void flatten(TreeNode* root) {
		if(root == nullptr)
			return;
		queue<TreeNode*> q;
		recrusive(root, q);
		q.pop();
		while(q.size() > 0){
			auto front = q.front();
			root->right = front;
			root->left = nullptr;
			root = front;
			q.pop();
		}
    }

	void recrusive(TreeNode* root, queue<TreeNode*>& q){
		if(root == nullptr)
			return;
		q.push(root);
		recrusive(root->left, q);
		recrusive(root->right, q);
	}
};
