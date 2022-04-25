#include <iostream>
#include <climits>
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

struct Status {
    int a, b, c;
};

class Solution {
public:
    Status dfs(TreeNode* root) {
        if (!root) {
            return {INT_MAX / 2, 0, 0};
        }
        auto [la, lb, lc] = dfs(root->left);
        auto [ra, rb, rc] = dfs(root->right);
        int a = lc + rc + 1;
        int b = min(a, min(la + rb, ra + lb));
        int c = min(a, lb + rb);
        return {a, b, c};
    }

    int minCameraCover(TreeNode* root) {
        auto [a, b, c] = dfs(root);
        return b;
    }
};


/* 
 *
 * class Solution {
 * private:
 *     unordered_map<TreeNode*, int> mp;
 * public:
 *     int minCameraCover(TreeNode* root) {
 *         return min(preOrder(root, false), 1 + preOrder(root, true));
 *     }
 *
 *     int preOrder(TreeNode* root, bool isIn) {
 *         if (root == nullptr)
 *             return 0;
 *         if (mp.count(root))
 *             return mp[root];
 *         int res = 0;
 *         // root is camera
 *         if (isIn) {
 *             res = preOrder(root->left, false) + preOrder(root->right, false);
 *         } else {
 *             res += 1;
 *             int tmp = 0;
 *             // root
 *             if (root->left && root->right) {
 *                 tmp = min(preOrder(root->left, true) + preOrder(root->right, false),
 *                             preOrder(root->right, true) + preOrder(root->left, false));
 *             } else if (root->left) {
 *                 tmp = min(tmp, preOrder(root->left, true));
 *             } else if (root->right) {
 *                 tmp = min(tmp, preOrder(root->right, true));
 *             }
 *
 *             res += tmp;
 *         }
 *
 *         mp[root] = res;
 *         return mp[root];
 *     }
 * }; */
