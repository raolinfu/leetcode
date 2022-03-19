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
    void recoverTree(TreeNode* root) {
		vector<TreeNode*> nodes;
		inoderTravel(root, nodes);
		TreeNode* n1 = nullptr;
		TreeNode* n2 = nullptr;
		for (int i = 0; i < nodes.size() - 1; i++) {
			if (nodes[i]->val > nodes[i + 1]->val) {
				if (n1 == nullptr) {
					n1 = nodes[i];
				} 
				n2 = nodes[i + 1];
			}
		}

		if (n1) {
			int tmp = n1->val;
			n1->val = n2->val;
			n2->val = tmp;
		}
    }
	void inoderTravel(TreeNode* root, vector<TreeNode*>& nodes) {
		if (root == nullptr)
			return;
		inoderTravel(root->left, nodes);
		nodes.push_back(root);
		inoderTravel(root->right, nodes);
	}
};
