#include <vector>
#include <queue>
#include <cstddef>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<ListNode*> listOfDepth(TreeNode* tree) {
        vector<ListNode*> ans;
        queue<TreeNode*> que;
        if (tree == nullptr)
            return ans;

        que.push(tree);
        while (!que.empty())
        {
            int n = que.size();
            ListNode dumpy(0);
            ListNode* pre = &dumpy;
            for (int i = 0; i < n; i++) {
                TreeNode* f = que.front();
                que.pop();
                pre->next = new ListNode(f->val);
                pre = pre->next;

                if (f->left)
                    que.push(f->left);

                if (f->right)
                    que.push(f->right);
            }

            ans.push_back(dumpy.next);
        }
        
        return ans;
    }
};



