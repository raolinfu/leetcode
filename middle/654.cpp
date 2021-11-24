#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* process(vector<int>&nums, int i, int j);
TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
	TreeNode *root;
	root = process(nums, 0, nums.size() - 1);
	return root;
}

TreeNode* process(vector<int>&nums, int i, int j){
	auto max_iter = max_element(nums.begin() + i, nums.begin() + j);
	int diff = distance(nums.begin() + i, max_iter);
	TreeNode* root = new TreeNode(*max_iter);
	cout<< root->val<< endl;
	if(diff == 0){
		root->left = nullptr;
	}else {
		root->left = process(nums, i, i + diff - 1);
	}
	if(diff == j - i){
		root->right = nullptr;
	}else {
		root->right = process(nums, i + diff + 1, j);
	}

	return root;
}
