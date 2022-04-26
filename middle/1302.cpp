#include <unordered_map>
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
    unordered_map<int, int> mp;
public:
    int deepestLeavesSum(TreeNode* root) {
        int idx = 0;
        int ans = 0;
        preOrder(root, 1);
        for (auto& iter: mp) {
            if (iter.first > idx) {
                idx = iter.first;
                ans = iter.second;
            }
        }

        return ans;
    }

    void preOrder(TreeNode* root, int h) {
        if (root == nullptr)
            return;
        mp[h] += root->val;
        preOrder(root->left, h + 1);
        preOrder(root->right, h + 1);
    }
};
