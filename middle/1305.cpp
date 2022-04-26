#include <vector>
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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> v1, v2;
        inOrder(root1, v1);
        inOrder(root2, v2);
        int i = 0;
        int j = 0;
        while (i < v1.size() || j < v2.size()) {
            if (i < v1.size() && j < v2.size()) {
                if (v1[i] <= v2[j]) {
                    ans.emplace_back(v1[i]);
                    i++;
                } else {
                    ans.emplace_back(v2[j]);
                    j++;
                }
            } else if (i < v1.size()) {
                ans.emplace_back(v1[i]);
                i++;
            } else {
                ans.emplace_back(v2[j]);
                j++;
            }
        }

        return ans;
    }

    void inOrder(TreeNode* root, vector<int>& nums) {
        if (root == nullptr)
            return;
        inOrder(root->left, nums);
        nums.emplace_back(root->val);
        inOrder(root->right, nums);
    }
};
