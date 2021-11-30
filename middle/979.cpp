#include<cmath>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int process(TreeNode* root, int &ans);
int distributeCoins(TreeNode* root) {
	int ans = 0;
	process(root, ans);
	return ans;
}

int process(TreeNode* root, int &ans){
	if(root == nullptr)
		return 0;
	int n = root->val - 1;
	int l = process(root->left, ans);
	int r = process(root->right, ans);
	ans += abs(l) + abs(r);

	return n + l + r;
}
