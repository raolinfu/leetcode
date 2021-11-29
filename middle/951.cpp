
#include<iostream>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool flipEquiv(TreeNode* root1, TreeNode* root2) {
	if(root1 == nullptr && root2 == nullptr)
		return true;
	else if(root1 == nullptr || root2 == nullptr)
		return false;

	bool r = root1->val == root2->val;
	bool left = flipEquiv(root1->left, root2->left);
	bool right = flipEquiv(root1->right, root2->right);

	bool leftRe = flipEquiv(root1->right, root2->left);
	bool rightRe = flipEquiv(root1->left, root2->right);

	return r && ((left && right) || (leftRe && rightRe));
}
