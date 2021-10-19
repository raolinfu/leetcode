#include<vector>
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

void process(TreeNode *root, vector<vector<int>> &res, vector<int> &nums, int sum, int &targetSum);
vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
	vector<vector<int>> res;
	vector<int> nums;
	process(root, res, nums, 0, targetSum);
	return res;
}

void process(TreeNode *root, vector<vector<int>> &res, vector<int> &nums, int sum, int &targetSum){
	if(root == nullptr)
		return;
	sum += root->val;
	nums.push_back(root->val);
	if(sum == targetSum && root->right == nullptr && root->left == nullptr)
	{
		res.push_back(nums);
		return;
	}
	if(root->left){
		process(root->left, res, nums, sum, targetSum);
		nums.pop_back();
	}
	if(root->right){
		process(root->right, res, nums, sum, targetSum);
		nums.pop_back();
	}
}
