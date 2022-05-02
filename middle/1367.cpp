#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    vector<int> next;
    vector<int> cmp;
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        while (head) {
            cmp.emplace_back(head->val);
            head = head->next;
        }
        next = vector<int>(cmp.size());
        int k = -1;
        int i = 0;
        next[0] = -1;
        while (i < cmp.size() - 1) { 
            if (k == - 1 || cmp[i] == cmp[k]) {
                k++;
                i++;
                next[i] = k;
            } else {
                k = next[k];
            }
        }
        vector<int> tmp;

        return backtrace(root, tmp);
    }
    bool backtrace(TreeNode* root, vector<int>& tmp) {
        if (root == nullptr) {
            return isValid(tmp, cmp, next);
        }
        tmp.emplace_back(root->val);
        bool left = backtrace(root->left, tmp);
        if (left)
            return true;
        bool right = backtrace(root->right, tmp);
        if (right)
            return true;
        tmp.pop_back();
        return false;
    }

    bool isValid(vector<int>& nums, vector<int>& cmp, vector<int>& next) {
        if (cmp.size() < next.size())
            return false;
        int i = 0;
        int j = 0;
        int l1 = nums.size();
        int l2 = cmp.size();
        while (i < l1 && j < l2) {
            if (j == -1 || nums[i] == cmp[j]) {
                i++;
                j++;
            } else {
                j = next[j];
            }
        }

        return j == l2;
    }

};
