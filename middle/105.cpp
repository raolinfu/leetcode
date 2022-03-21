#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
    }

	TreeNode* buildTree(vector<int>& preorder, int i1, int j1, vector<int>& inorder, int i2, int j2) {
		if (i1 > j1)
			return nullptr;
		if (i1 == j1)
			return new TreeNode(preorder[i1]);
		int m = getIndex(inorder, i2, j2, preorder[i1]);
		TreeNode* root = new TreeNode(preorder[i1]);
		root->left = buildTree(preorder, i1 + 1, i1 + m - i2, inorder, i2, m - 1);
		root->right = buildTree(preorder, j1 + m + 1 - j2, j1, inorder, m + 1, j2);
		return root;
	}
	int getIndex(vector<int>& inorder, int a, int b, int tar) {
		int i = a;
		for (; i <= b; i++) {
			if (inorder[i] == tar)
				break;
		}
		return i;
	}
};
