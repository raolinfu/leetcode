#include <vector>
#include <unordered_set>
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
private:
    unordered_set<TreeNode*> res;
    unordered_set<int> st;
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (root == nullptr)
            return {{}};
        for (auto n: to_delete)
            st.insert(n);

        root = postOrder(root);
        if (root)
            res.insert(root);

        vector<TreeNode*> ans(res.begin(), res.end());
        return ans;
    }

    TreeNode* postOrder(TreeNode* root) {
        if (root == nullptr)
            return nullptr;
        root->left = postOrder(root->left);
        root->right = postOrder(root->right);
        if (st.count(root->val)) {
            if (root->left)
                res.insert(root->left);
            if (root->right)
                res.insert(root->right);

            delete root;
            return nullptr;
        }

        return root;
    }
};
