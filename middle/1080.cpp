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

class Solution {
public:
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
		int preSum = 0;
		auto ans = helper(root, limit, preSum);
		return ans.first < limit? nullptr: root;
    }

	pair<int, int> helper(TreeNode* root, int& limit, int preSum){
		if(root == nullptr)
			return {preSum, 0};
        //cout<< "root: "<< root->val<< endl;

		auto left = helper(root->left, limit, preSum + root->val);
		auto right = helper(root->right, limit, preSum + root->val);
		
		int cur = preSum + root->val;
        int blow = root->val;
		if(root->left && root->right){
			cur += max(left.second, right.second);
            blow += max(left.second, right.second);
        }
		else if(root->left || root->right){
			cur += root->left? left.second: right.second;
            blow += root->left? left.second: right.second;
        }

		// 上面先比较，后设置为空指针
		if(left.first < limit)
			root->left = nullptr;
		if(right.first < limit)
			root->right = nullptr;
		return {cur, blow};
		if(root == nullptr)
			return {preSum, 0};
	}
};
