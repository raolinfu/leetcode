#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return nullptr;
        TreeNode* cur = root;
        while (cur)
        {
            if (cur->val < q->val && cur->val < p->val) {
                cur = cur->right;
            } else if (cur->val > q->val && cur->val > p->val) {
                cur = cur->left;
            } else {
                break;
            }
        }
        
        return cur;
    }
};