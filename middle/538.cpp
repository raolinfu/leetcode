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

void process(TreeNode* root, int& sum);
TreeNode* convertBST(TreeNode* root) {
	int sum = 0;
	process(root, sum);

	return root;
}

void process(TreeNode* root, int& sum){
	if(root == nullptr){
		sum += 0;
		return;
	}
	process(root->right, sum);
	sum += root->val;
	root->val = sum;
	process(root->left, sum);
}
