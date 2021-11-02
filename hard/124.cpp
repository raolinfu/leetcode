#include<iostream>
#include<climits>
#include<utility>
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
    int maxPathSum(TreeNode* root) {
		int result = INT_MIN;
		auto pair =	process(root, result);
		return result;
    }

	pair<int, int> process(TreeNode* root, int &result){
		if(root == nullptr)
			return make_pair(0, 0);
		auto left = process(root->left, result);
		auto right = process(root->right, result);
		int res = root->val;
		int max_left = max(left.first, left.second);
		int max_right = max(right.first, right.second);
		int cur_left = res;
		int cur_right = res;
		// 注意只有左右有一个大于0时 才需要加进去比较
		if( max_left> 0){
			res += max_left;
			cur_left += max_left;
		}
		if( max_right > 0){
			res += max_right;
			cur_right += max_right;
		}
		result = max(result, res);
		return make_pair(cur_left, cur_right);
	}
};
