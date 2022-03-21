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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		return buildTree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }

	TreeNode* buildTree(vector<int>& inorder, int i1, int j1, vector<int>& postorder, int i2, int j2) {
		if (i1 > j1)
			return nullptr;
		if (i1 == j1)
			return new TreeNode(inorder[i1]);

		int m = getIndex(inorder, i1, j1, postorder[j2]);
		TreeNode* root = new TreeNode(postorder[j2]);
		root->right = buildTree(inorder, m + 1, j1, postorder, j2 - j1 + m, j2 - 1);
		root->left = buildTree(inorder, i1, m - 1, postorder, i2, i2 + m - i1 - 1);

		return root;
	}

	int getIndex(vector<int>& inorder, int a, int b, int tar) {
		int i = a;
		while (i <= b) {
			if (inorder[i] == tar)
				break;
			i++;
		}
		return i;
	}
};
