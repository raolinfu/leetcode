#include<iostream>
#include<unordered_map>
using namespace std;
/*
 *打劫3 f(root) = max(f(right) + f(left), root->vale + f(right->left)+ f(right->left+ f(left->left+ f(left->right))))
 * */
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

int process(TreeNode* root, unordered_map<TreeNode*, int> &mp);
int rob(TreeNode* root) {
	unordered_map<TreeNode*, int> mp;
	return process(root, mp);
}
/*如果不预先保存算出来的结果 会超时*/
int process(TreeNode* root, unordered_map<TreeNode*, int> &mp){
	int res;
	if(!root)
		return 0;
	int first = process(root->right, mp) + process(root->left, mp);
	int second = root->val;
	if(root->right)
		second = second
			+ (mp.find(root->right->right) != mp.end()? mp[root->right->right]: process(root->right->right, mp))
			+ (mp.find(root->right->left) != mp.end()? mp[root->right->left]: process(root->right->left, mp));
	if(root->left)
		second = second
			+ (mp.find(root->left->right) != mp.end()? mp[root->left->right]: process(root->left->right, mp))
			+ (mp.find(root->left->left) != mp.end()? mp[root->left->left]: process(root->left->left, mp));

	res = max(first, second);
	mp.insert({root, res});
	return res;
}
