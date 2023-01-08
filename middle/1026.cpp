#include <map>
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
    map<int, int> mp;
    int res = 0;
public:
    int maxAncestorDiff(TreeNode* root) {
        preOrder(root);
        return res;
    }

    void preOrder(TreeNode* root) {
        if (root == nullptr) {
            res = max(abs(mp.begin()->first - mp.rbegin()->first), res);
            return;
        }
        ++mp[root->val];

        preOrder(root->left);
        preOrder(root->right);

        --mp[root->val];
        if (mp[root->val] == 0) {
            mp.erase(root->val);
        }
    }
};