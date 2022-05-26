#include <string>
#include <vector>
#include <iostream>
#include <queue>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> que;
        que.push(root);
        ans += std::to_string(root->val);
        ans += ":";
        while (!que.empty()) {
            auto f = que.front();
            que.pop();
            TreeNode* left = f->left;
            TreeNode* right = f->right;
            if (left) {
                ans += std::to_string(left->val);
                que.push(left);
            } else {
                ans += "!";
            }
            ans += ":";

            if (right) {
                ans += std::to_string(right->val);
                que.push(right);
            } else {
                ans += "!";
            }
            ans += ":";
        }
        
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data.empty())
            return nullptr;

        vector<string> strs;
        string tmp;
        for (char ch: data) {
            if (ch == ':') {
                strs.push_back(tmp);
                tmp.clear();
            } else if (ch == '!') {
                continue;
            } else {
                tmp += ch;
            }
        }

        queue<TreeNode*> que;
        int i = 0;
        TreeNode* root = new TreeNode(std::stoi(strs[i]));
        que.push(root);
        i++;

        while (!que.empty()) {
            auto cur = que.front();
            que.pop();

            // 左节点
            if (strs[i].empty()) {
                cur->left = nullptr;
            } else {
                TreeNode* left = new TreeNode(std::stoi(strs[i]));
                cur->left = left;
                que.push(left);
            }
            i++;

            // 右节点
            if (strs[i].empty()) {
                cur->right = nullptr;
            } else {
                TreeNode* right = new TreeNode(std::stoi(strs[i]));
                cur->right = right;
                que.push(right);
            }
            i++;
        }

        return root;
    }
};

// Your Codec object wilal be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
