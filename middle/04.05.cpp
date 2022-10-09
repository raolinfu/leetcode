#include <cstddef>
#include <climits>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, INT_MAX, INT_MIN);
    }

    bool dfs(TreeNode* root, int hi, int lo) {
        if (root == nullptr)
            return true;

        if (root->left && root->val <= root->left->val)
            return false;

        if (root->right && root->val >= root->right->val)
            return false;
        
        if (root->val < lo || root->val > hi)
            return false;

        bool l = dfs(root->left, root->val, lo);

        bool r = dfs(root->right, hi, root->val);

        return l && r;

    }
};