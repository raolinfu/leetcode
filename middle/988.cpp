#include <string>
#include <algorithm>
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
public:
     string smallestFromLeaf(TreeNode* root) {
        string ans;
        string tmp;
        preOrder(root, tmp, ans);

        return ans;
    }

    void preOrder(TreeNode* root, string& tmp, string& ans) {
        tmp.push_back(root->val + 'a');
        if (root->left == nullptr && root->right == nullptr) {
            reverse(tmp.begin(), tmp.end());
            if (ans.empty()) {
                ans = tmp;
            }
            else{
                ans = ans < tmp? ans: tmp; 
            }
            reverse(tmp.begin(), tmp.end());
            tmp.pop_back();
            return;
        }
        
        if (root->left)
            preOrder(root->left, tmp, ans);
        if (root->right)
            preOrder(root->right, tmp, ans);
        tmp.pop_back();
    }
};

