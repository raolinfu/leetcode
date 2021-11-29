#include<iostream>
#include<climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool process(TreeNode* root, long  low, long  high);
bool isValidBST(TreeNode* root) {
	return process(root, LONG_MIN, LONG_MAX);
}

bool process(TreeNode* root, long  low, long  high){
	if(root == nullptr)
		return true;
	bool cur = root->val > low && root->val < high;	
	bool l = process(root->left, low, root->val);
	bool r = process(root->right, root->val, high);
	return cur && l && r;
}
