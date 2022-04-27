#include <vector>
#include <queue>
#include <climits>
#include <iostream>
#include <algorithm>
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
    unordered_map<int, pair<vector<int>, vector<int>>> mp;
    int min_cols = INT_MAX;
    int max_cols = INT_MIN;
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});
        while (!que.empty()) {
            auto f = que.front();
            int row = f.second.first;
            int col = f.second.second;
            int hashNum = row * 2001 + col;
            mp[col].first.push_back(hashNum);
            mp[col].second.push_back(f.first->val);
            min_cols = min(min_cols, col);
            max_cols = max(max_cols, col);
            que.pop();

            if (f.first->left) {
                que.push({f.first->left, {row + 1, col - 1}});
            }

            if (f.first->right) {
                que.push({f.first->right, {row + 1, col + 1}});
            }
        }

        // preOrder(root, 0, 0);
        vector<vector<int>> ans(max_cols - min_cols + 1, vector<int>());

        for (auto& [k, v]: mp) {
             sortNums(v.first, v.second);
             ans[k - min_cols] = v.second;
        }

        return ans;
    }

    void preOrder(TreeNode* root, int row, int col) {
        if (root == nullptr)
            return;

        min_cols = min(min_cols, col);
        max_cols = max(max_cols, col);

        int hashNum = 2001 * row + col;
        mp[col].first.push_back(hashNum);
        mp[col].second.push_back(root->val);
        preOrder(root->left, row + 1, col - 1);
        preOrder(root->right, row + 1, col + 1);
    }

    void sortNums(vector<int>& nums, vector<int>& vals) {
        int l = 0;
        int r = 0;
        while (r < nums.size()) {
            if (nums[r] == nums[l]) {
                r++;
            } else {
                sort(vals.begin() + l, vals.begin() + r);
                l = r;
            }
        }
        sort(vals.begin() + l, vals.end());
    }
};
int main() {
    vector<int> nums {1, 7, 2, 3, 4};
    sort(nums.begin(), nums.begin() + 3);
    for (auto n :nums)
        cout<< n<< endl;
    
    return 0;
}
