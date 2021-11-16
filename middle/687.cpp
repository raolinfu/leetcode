#include<iostream>
#include<utility>
#include<climits>
using namespace std;
/* 
 *	路径分两种 横跨两边的 以及从上至下的
 * */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int process(TreeNode* root, int &res);
int longestUnivaluePath(TreeNode* root) {
	int res = 0;
	process(root, res);
	return res - 1;
}

int process(TreeNode* root, int &res){
	if(root == nullptr)
		return 0;
	int l = process(root->left, res);	
	int r = process(root->right, res);	
	int n = 1;
	int cmp = 1;
	if(root->left && root->left->val == root->val){
		n = max(n, l + 1);	
		cmp += l;
	}
	if(root->right && root->right->val == root->val){
		n = max(n, r + 1);	
		cmp += r;
	}
	res = max(res, cmp);

	return n;
}
