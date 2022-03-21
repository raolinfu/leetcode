
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
public:
    TreeNode* sortedListToBST(ListNode* head) {
		ListNode* t = head;
		int len = 0;
		while (t) {
			len++;
			t = t->next;
		}

		return buildTree(head, len);
    }

	TreeNode* buildTree(ListNode* head, int len) {
		if (len <= 0)
			return nullptr;
		if (len == 1)
			return new TreeNode(head->val);
		ListNode* cur = head;
		int i = 0;
		while (i < len / 2) {
			cur = cur->next;
			i++;
		}
		TreeNode* root = new TreeNode(cur->val);
		root->left = buildTree(head, len / 2);
		root->right = buildTree(cur->next, len - len / 2 - 1);
		return root;
	}
};
