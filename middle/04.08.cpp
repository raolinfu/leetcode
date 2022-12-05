#include <cstddef>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    int cnt = 0;
    bool flag = false;
    TreeNode* res = nullptr;
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return res;
    }

    void dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr || flag == true)
            return;

        dfs(root->left, p, q);
        dfs(root->right, p, q);

        if (root->val == p->val || root->val == q->val) {
            cnt++;
        }

        if (cnt == 2 && flag == false) {
            flag = true;
            res = root;
        }
    }
};