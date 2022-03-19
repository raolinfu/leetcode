
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
    int sumNumbers(TreeNode* root) {
		int sum = 0;
		traveler(root, sum, 0);

		return sum;
    }

	void traveler(TreeNode* root, int& sum, int n) {
		if (root == nullptr)
			return;
		int cur = n * 10 + root->val;
		if (root->left == nullptr && root->right == nullptr) {
			sum += cur;
			return;
		}
		traveler(root->left, sum, cur);
		traveler(root->right, sum, cur);
	}
};
