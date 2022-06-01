#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
private:
    queue<TreeNode*> que;
public:
    BSTIterator(TreeNode* root) {
        inOrder(root);
    }
    
    int next() {
        auto f = que.front();
        que.pop();
        return f->val;
    }
    
    bool hasNext() {
        return !que.empty();
    }

    void inOrder(TreeNode* root) {
        if (root == nullptr)
            return;
        inOrder(root->left);
        que.push(root);
        inOrder(root->right);
    }
};
