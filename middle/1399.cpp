#include <climits>
#include <cmath>
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
    unordered_map<TreeNode*, pair<long, long>> mp;
public:
    int maxProduct(TreeNode* root) {
        int mod = pow(10, 9) + 7;
        long ans = INT_MIN;
        long sum = postOrder(root);
        for (auto [k, v]: mp) {
            long cmp = max(v.first * (sum - v.first), v.second * (sum - v.second));
            ans = max(ans, cmp);
        }

        return ans % mod;
    }

    long postOrder(TreeNode* root) {
        if (root == nullptr)
            return 0;
        long left = postOrder(root->left);
        long right = postOrder(root->right);
        mp.insert({root, {left, right}});

        return left + right + root->val;
    }
};
