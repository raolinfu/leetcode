#include <cstddef>
#include <stack>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    stack<TreeNode*> stk;
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);
        while (!stk.empty())
        {
            auto t = stk.top();
            stk.pop();
            if (!stk.empty() && stk.top() == p) {
                return t;
            }
        }
        return nullptr;
    }

    void dfs(TreeNode* root, TreeNode* p) {
        if (root == nullptr)
            return;
        dfs(root->left, p);
        stk.push(root);
        dfs(root->right, p);
    }
};